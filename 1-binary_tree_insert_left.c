#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node for a binary tree and inserts it
 *  as the left-child of another node, making the original parent's left-child
 *  node become the new child's left-child node
 *
 * @parent: The node above the new node in the tree
 * @value: Integer stored in the node
 *
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node)
	{
		new_node->left = parent->left;
		parent->left = new_node;
	}

	return (new_node);
}
