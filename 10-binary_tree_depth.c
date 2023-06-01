#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of an element in a binary tree
 *
 * @tree: pointer to the node of the tree whose depth is required
 *
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
