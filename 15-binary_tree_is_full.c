#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full, ie if
 *  all nodes either have 2 children or none
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left)
	{
		if (tree->right)
			return (
				binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right)
			);
		return (0);
	}
	if (tree->right)
		return (0);
	return (1);
}
