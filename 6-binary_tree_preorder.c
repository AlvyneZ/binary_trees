#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order
 *  traversal calling a function on each node's value
 *
 * @tree: pointer to the root node of the tree to be traversed
 * @func: pointer to the function to call for each node
 *
 * Return: none
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree)
	{
		(*func)(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
