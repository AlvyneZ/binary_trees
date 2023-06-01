#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node of the tree
 * @second: pointer to the second node of the tree
 *
 * Return: the lowest common ancestor of the node,
 *  or NULL if it cannot be found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *curf, *curs;

	if ((first == NULL) || (second == NULL))
		return (NULL);
	for (curf = first; curf != NULL; curf = curf->parent)
	{
		for (curs = second; curs != NULL; curs = curs->parent)
		{
			if (curf == curs)
				return (curf);
		}
	}
	return (NULL);
}
