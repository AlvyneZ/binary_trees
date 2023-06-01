#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if ((tree == NULL) || (tree->right == NULL))
		return (tree);
	/* Setting tree->right as newroot */
	newroot = tree->right;
	newroot->parent = NULL;
	/* Moving newroot->left over to tree */
	tree->right = newroot->left;
	newroot->left->parent = tree;
	/* Moving tree over to newroot */
	newroot->left = tree;
	tree->parent = newroot;

	return (newroot);
}
