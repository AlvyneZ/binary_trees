#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of leaves of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		return (
			binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right)
		);
	return (1);
}
