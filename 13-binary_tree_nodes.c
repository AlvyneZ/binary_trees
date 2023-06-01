#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with children
 *  in a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		return (1 +
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right)
		);
	return (0);
}
