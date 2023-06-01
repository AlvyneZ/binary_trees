#include "binary_trees.h"

/**
 * binary_tree_perfect_height - Measures the height of a binary tree
 *  including the current node in the measurement only if its sibling
 *  subtrees are perfect, then updates the perfect state of the tree
 *
 * @tree: pointer to the root node of the tree
 * @perfect: [out] whether the subtrees are perfect
 *
 * Return: the height of the tree
 */
static size_t binary_tree_perfect_height(const binary_tree_t *tree,
		int *perfect)
{
	size_t hl, hr = 0;

	if ((tree == NULL) || (!(*perfect)))
		return (0);
	hl = binary_tree_perfect_height(tree->left, perfect);
	if (*perfect)
	{
		hr = binary_tree_perfect_height(tree->right, perfect);
		if (hl == hr)
			return (hl + 1);
		*perfect = 0;
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect, ie if
 *  each subtree has a 0 balancing factor
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 1;

	if (tree == NULL)
		return (0);
	binary_tree_perfect_height(tree, &perfect);
	return (perfect);
}
