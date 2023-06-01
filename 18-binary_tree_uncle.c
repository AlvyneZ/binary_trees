#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node ie the node
 *  with the same parent as the current node's parent
 *
 * @tree: pointer to the node of the tree
 *
 * Return: the uncle of the node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL) ||
			(node->parent->parent == NULL))
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	/* No need to check if node is the child to the right */
	return (node->parent->parent->left);
}
