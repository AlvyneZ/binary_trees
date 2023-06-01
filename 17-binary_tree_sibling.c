#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node ie the node
 *  with the same parent
 *
 * @node: pointer to the node of the tree
 *
 * Return: the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL))
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	/* No need to check if node is the child to the right */
	return (node->parent->left);
}
