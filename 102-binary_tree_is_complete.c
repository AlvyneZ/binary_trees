#include "binary_trees.h"

/**
 * binary_tree_complete_check - Goes through subtrees starting
 *  at different levels to check if they are complete
 *
 * @tree: pointer to the root node of the subtree
 * @cmplvl: the level at which all subtrees should reach
 * @moved: whether the cmplvl has been moved up from the last level
 * @rootlvl: the level at which the subtree root is
 *
 * Return: 1 if subtree is complete, otherwise 0
 */
static int binary_tree_complete_check(const binary_tree_t *tree,
		size_t *cmplvl, int *moved, size_t rootlvl)
{
	if ((tree == NULL) || (rootlvl > *cmplvl))
		return (0);
	/* For all the levels above the second last level */
	if ((rootlvl + 1) < (*cmplvl))
		return (
			binary_tree_complete_check(tree->left, cmplvl, moved, rootlvl + 1)
			&&
			binary_tree_complete_check(tree->right, cmplvl, moved, rootlvl + 1)
		);
	/* The levels at the bottom must not have children */
	if (rootlvl == *cmplvl)
		return ((tree->left == NULL) && (tree->right == NULL));
	/* The second last levels can have the expected complete pushed up*/
	if (tree->left == NULL)
	{
		if (*moved)
			return (0);
		*cmplvl -= 1;
		*moved = 1;
		return (tree->right == NULL);
	}
	if (tree->left->left || tree->left->right)
		return (0);
	if (tree->right == NULL)
	{
		if (*moved)
			return (0);
		*cmplvl -= 1;
		*moved = 1;
		return (1);
	}
	return ((tree->right->left == NULL) && (tree->right->right == NULL));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete, ie if
 *  only the lowest level is missing elements and is filled from the left
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t lvls = 0;
	int mv = 0;
	const binary_tree_t *cur;

	if (tree == NULL)
		return (0);
	for (cur = tree->left; cur != NULL; cur = cur->left)
		lvls++;
	return (binary_tree_complete_check(tree, &lvls, &mv, 0));
}
