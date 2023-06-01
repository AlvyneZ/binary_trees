#include "binary_trees.h"

/**
 * binary_tree_insert_right - Creates a new node for a binary tree and inserts
 *  it as the right-child of another node, making the original parent's
 *  right-child node become the new child's right-child node
 *
 * @parent: The node above the new node in the tree
 * @value: Integer stored in the node
 *
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node)
	{
		new_node->right = parent->right;
		parent->right = new_node;
		if (new_node->right)
			new_node->right->parent = new_node;
	}

	return (new_node);
}
