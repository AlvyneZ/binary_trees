#include "binary_trees.h"
#include <string.h>
#include <stdio.h>

#define __LEVEL_BUFFER_SIZE		32
#define __MAX(a, b)		(((a) >= (b)) ? (a) : (b))

/**
 * binary_tree_level_cnt - Measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
static size_t binary_tree_level_cnt(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		return (1 +
			__MAX(
				binary_tree_level_cnt(tree->left),
				binary_tree_level_cnt(tree->right)
			)
		);
	return (0);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *  traversal calling a function on each node's value
 *
 * @tree: pointer to the root node of the tree to be traversed
 * @func: pointer to the function to call for each node
 *
 * Return: none
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t bufSize = __LEVEL_BUFFER_SIZE, curcnt = 1, nxtcnt, i, j;
	const binary_tree_t **curlvl, **nxtlvl;

	if ((tree == NULL) || (func == NULL))
		return;
	curlvl = malloc(bufSize * sizeof(binary_tree_t *));
	nxtlvl = malloc(bufSize * sizeof(binary_tree_t *));
	if ((curlvl == NULL) || (nxtlvl == NULL))
		goto FREE;
	curlvl[0] = tree;
	for (i = 0; i <= binary_tree_level_cnt(tree); i++)
	{
		for (j = 0, nxtcnt = 0; j < curcnt; j++)
		{
			(*func)(curlvl[j]->n);
			if (nxtcnt >= (bufSize - 2))
			{
				bufSize += __LEVEL_BUFFER_SIZE;
				nxtlvl = realloc(nxtlvl, bufSize * sizeof(binary_tree_t *));
				if (nxtlvl == NULL)
					goto FREE;
			}
			if (curlvl[j]->left)
				nxtlvl[nxtcnt++] = (const binary_tree_t *)curlvl[j]->left;
			if (curlvl[j]->right)
				nxtlvl[nxtcnt++] = (const binary_tree_t *)curlvl[j]->right;
		}
		curcnt = nxtcnt;
		if (curcnt >= bufSize)
			curlvl = realloc(curlvl, bufSize * sizeof(binary_tree_t *));
		if (curlvl == NULL)
			goto FREE;
		memcpy(curlvl, nxtlvl, curcnt * sizeof(binary_tree_t *));
	}
FREE:
	if (nxtlvl != NULL)
		free(nxtlvl);
	if (curlvl != NULL)
		free(curlvl);
}
