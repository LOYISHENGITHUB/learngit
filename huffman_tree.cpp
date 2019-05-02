//filename: huffman_tree.cpp
//author: PenG
//create time: 2019/04/26

#include "huffman_tree.h"

const unsigned int SIZE = 8;

//for amount: every time combine will adding a node, so cycle is SIZE+k times
int get_min_weight(Node *node_queue, int amount)
{
    /*
    * now I define when the node was delete then its weight will be 
    * negetive.
    */
    int min = 999999999;
    int index = -1;
    for (int i=0; i<amount; i++)
    {
        //if node[i].weight > 0, get the minimum weight node index
        if (min > node_queue[i].weight && node_queue[i].weight > 0)
        {
            min = node_queue[i].weight;
            index = i;
        }
    }
    node_queue[index].weight *= -1; //negetive instead of delete in queue
    return index;
}

void combine_node(Node *node_queue, int lchild_index,
                  int rchild_index, int parent_index)
{
    node_queue[parent_index].weight = node_queue[lchild_index].weight + node_queue[rchild_index].weight;
    node_queue[parent_index].weight *= -1;

    node_queue[parent_index].data = 'N';

    node_queue[parent_index].parent = -1;

    node_queue[parent_index].lchild = lchild_index;
    node_queue[parent_index].rchild = rchild_index;

    node_queue[lchild_index].parent = parent_index;
    node_queue[rchild_index].parent = parent_index;
}

void huffman_tree(void)
{
	//2n-1 node to store the huffman tree
	struct Node node[SIZE * 2 - 1];
    //add source data to node
	for (int i=0; i<SIZE;) 
    {
        int num;
        cout << "Please input the weight:";
        cin >> num;
        if (num < 1)
        {
            cout << "Error input!\nPlease input again!" << endl;
            continue;
        }
        node[i].weight = num;

        cout << "Please input the charater:";
        cin >> node[i].data; //data type is char
        node[i].lchild = -1;
        node[i].rchild = -1;
        node[i].parent = -1;
        
        i++;
    }

    //sort
    //sort_by_weight(node, SIZE);

    //create huffman tree
    int min1_index = -1;
    int min2_index = -1;
    for (int i=0; i<SIZE-1; i++)
    {
        //get two minimum number in node queue weight
        min1_index = get_min_weight(node, SIZE + i);
        min2_index = get_min_weight(node, SIZE + i);

        combine_node(node, min1_index, min2_index, SIZE + i);
    }

    //ouput the result
    for (int i=0; i<2*SIZE - 1; i++)
    {
        cout << "No." << i << "  ";
        cout << "weight:" << node[i].weight << "  data:" << node[i].data << "  ";
        cout << "parent:" << node[i].parent << "  ";
        cout << "lchild:" << node[i].lchild << "  "
            << "rchild:" << node[i].rchild << endl;
    }
}

