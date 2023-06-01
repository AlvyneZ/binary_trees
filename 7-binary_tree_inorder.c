#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order
 *  traversal calling a function on each node's value
 *
 * @tree: pointer to the root node of the tree to be traversed
 * @func: pointer to the function to call for each node
 *
 * Return: none
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree)
	{
		binary_tree_inorder(tree->left, func);
		(*func)(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
