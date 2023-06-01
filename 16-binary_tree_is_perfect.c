#include "binary_trees.h"

/**
 * binary_tree_balance_height - Measures the height of a binary tree
 *  including the current node in the measurement
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
static size_t binary_tree_balance_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 +
		__MAX(
			binary_tree_balance_height(tree->left),
			binary_tree_balance_height(tree->right)
		)
	);
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
	if (tree == NULL)
		return (0);
	if (binary_tree_balance_height(tree->left) !=
			binary_tree_balance_height(tree->right))
		return (0);
	if (tree->left)
	{
		if (tree->right)
			return (
				binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right)
			);
		return (0);
	}
	if (tree->right)
		return (0);
	return (1);
}
