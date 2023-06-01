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
	size_t depf = 0, deps = 0;

	if ((first == NULL) || (second == NULL))
		return (NULL);
	for (curf = first->parent; curf != NULL; curf = curf->parent)
		depf++;
	for (curs = second->parent; curs != NULL; curs = curs->parent)
		deps++;
	for (curf = first; depf > deps; curf = curf->parent)
		depf--;
	for (curs = second; deps > depf; curs = curs->parent)
		deps--;
	while ((curf != NULL) && (curs != NULL))
	{
		if (curf == curs)
			return (curf);
		curf = curf->parent;
		curs = curs->parent;
	}
	return (NULL);
}
