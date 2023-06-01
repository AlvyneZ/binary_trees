# Binary Trees
### Author: AlvyneZ
This repository contains C program source code for implementing binary trees in C.  
_Note:_ The trees implemented in the first 23 tasks (0-18 and 100-104) are simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.  

## binary_tree_print
This function is initially provided for printing the trees in a pretty way.  
\
SYNOPSIS:  
```
#include "binary_trees.h"
void binary_tree_print(const binary_tree_t *tree);  
```
\
The output looks as follows:  
```
                           .----------------------(006)-------.
                      .--(001)-------.                   .--(008)--.
                 .--(-02)       .--(003)-------.       (007)     (009)
       .-------(-06)          (002)       .--(005)
  .--(-08)--.                           (004)
(-09)     (-07)
```
\
Sourced from [GitHub (holbertonschool)](https://github.com/holbertonschool/0x1C.c)  
Original code from [StackOverflow (C How to "draw" a Binary Tree to the console)](http://stackoverflow.com/a/13755911/5184480)  

## Functions implemented for simple trees
SYNOPSIS:
```
#include "binary_trees.h"

/* Functions for creation and deletion of nodes of the tree */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);

/* Fucntions for checking type of nodes of the tree */
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);

/* Functions for traversing the tree's nodes */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Functions to get dimensions and measures of a tree */
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/* Functions that check the conditions of a tree */
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);

/* Functions to retrieve node relatives */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second);

/* Functions to rotate binary trees */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
```