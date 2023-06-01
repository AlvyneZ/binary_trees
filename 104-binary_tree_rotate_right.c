#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if ((tree == NULL) || (tree->left == NULL))
		return (tree);
	/* Setting tree->left as newroot */
	newroot = tree->left;
	newroot->parent = NULL;
	/* Moving newroot->right over to tree */
	tree->left = newroot->right;
	if (tree->left)
		tree->left->parent = tree;
	/* Moving tree over to newroot */
	newroot->right = tree;
	newroot->right->parent = newroot;

	return (newroot);
}
