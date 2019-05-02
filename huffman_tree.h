//filename: huffman_tree.h
//author: PenG
//create time: 2019/04/26

#ifndef _HUFFMAN_TREE_H
#define _HUFFMAN_TREE_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct Node
{
	int weight;
    char data;
	int lchild;
	int rchild;
	int parent;
}Node;

int get_min_weight(Node *node_queue, int amount);

void combine_node(Node *node_queue, int lchild_index,
                 int rchild_index, int parent_index);

void huffman_tree(void);

#endif
