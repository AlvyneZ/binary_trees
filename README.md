# Binary Trees
### Author: AlvyneZ
This repository contains C program source code for implementing binary trees in C.  
_Note:_ The trees implemented in the first 23 tasks are simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.  

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
