#include <stdio.h>
#include <stdlib.h>

typedef struct  s_bintree
{
    int data;
    struct  s_bintree *left;
    struct  s_bintree *right;
} t_bt;

/*
==========================
	Standard Methods
==========================
*/

t_bt *t_bt_start		(void);
t_bt *t_bt_free_tree		(t_bt *t);
t_bt *t_bt_find_first		(t_bt *t, int searched_elem);
t_bt *t_bt_find_greatest	(t_bt *t);
t_bt *t_bt_find_smallest	(t_bt *t);

/*
==========================
	Insert Methods
==========================
*/

t_bt *t_bt_insert		(int new_data, t_bt *left, t_bt *right);

// @Method Name: t_bt_insert_left() / t_bt_insert_right() 
// Both these methods creates a new node with NULL/NULL sub-trees and then link it to the 
// parent node's left or right branch depending on the method called.
// Safe and unsafe methods are implemented. The unsafe one WILL OVERWRITE the sub-tree no 
// matter what. The safe method will only add the new node if the chosen sub-tree is NULL.
// @params: 
// 	1) original tree pointer;
// 	2) a parent node pointer where the new node will be added;
// 	3) new node info;
// @returns: 
// 	1) original tree pointer;

t_bt *t_bt_insert_left_safe (t_bt *t, t_bt *parent_node, int new_node_data);
t_bt *t_bt_insert_right_safe	(t_bt *t, t_bt *parent_node, int new_node_data);
t_bt *t_bt_insert_left_unsafe	(t_bt *t, t_bt *parent_node, int new_node_data);
t_bt *t_bt_insert_right_unsafe	(t_bt *t, t_bt *parent_node, int new_node_data);

/*
=============
Print Methods
1) Pre-order	-> node, left, right
2) In-order		-> left, node, right
3) Post-order	-> left, right, node
4) Level-order
=============
*/

void t_bt_print_pre		(t_bt *t);
void t_bt_print_in		(t_bt *t);
void t_bt_print_pos		(t_bt *t);