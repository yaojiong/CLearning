//
//  tree.h
//  tree
//
//  Created by jiadoggy on 2017/3/5.
//  Copyright © 2017年 jiadoggy. All rights reserved.
//

#ifndef tree_h
#define tree_h
#include <stdbool.h>

#define SLEN 20
typedef struct item {
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEMS 10

typedef struct trnode {
    Item item;
    struct trnode * left; // pointer to left
    struct trnode * right; // pointer to right
} Trnode;

typedef struct tree {
    Trnode * root; // pointer to the root of the tree
    int size;      // the number of the node
} Tree;

// function
void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree);

bool DeleteItem(const Item * pi, Tree * ptree);

void Traverse(const Tree * ptree, void(*pfun)(Item item));

void DeleteAll(Tree * ptree);
#endif /* tree_h */
