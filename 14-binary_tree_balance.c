#include "binary_trees.h"

#define __MAX(a, b)		(((a) >= (b)) ? (a) : (b))

/**
 * binary_tree_balance_height - Measures the height of a binary tree
 *  including the current node in the measurement
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
static size_t binary_tree_balance_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 +
		__MAX(
			binary_tree_balance_height(tree->left),
			binary_tree_balance_height(tree->right)
		)
	);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (
		(int)(binary_tree_balance_height(tree->left)) -
		(int)(binary_tree_balance_height(tree->right))
	);
}
