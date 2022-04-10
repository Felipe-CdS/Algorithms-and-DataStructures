#include "binary-tree.h"
#include <string.h>

t_bt    *t_bt_start(void)
{
    return NULL;
}

t_bt    *t_bt_free_tree(t_bt *t)
{
    if(t){
        t_bt_free_tree(t->left);
        t_bt_free_tree(t->right);
        free(t);
    }
}

t_bt *t_bt_find_first	(t_bt *t, int searched_elem)
{   
    t_bt *aux;

    if(!t || t->data == searched_elem) return t;
    aux = t_bt_find_first(t->left, searched_elem);
    if(aux) return aux;
    return t_bt_find_first(t->right, searched_elem);
}

t_bt *t_bt_find_greatest    (t_bt *t)
{   
    t_bt *left, *right, *greatest;    

    if(!t) return NULL;
    
    left = t_bt_find_greatest(t->left);
    right = t_bt_find_greatest(t->right);  

    if(!left && !right) return t;
    else
    {
        if(left->data >= right->data) greatest = left;
        else greatest = right;
    }

    if(t->data >= greatest->data) return t;
    else return greatest;
}

t_bt *t_bt_find_smallest	(t_bt *t)
{   
    t_bt *left, *right, *smallest;    

    if(!t) return NULL;
    
    left = t_bt_find_smallest(t->left);
    right = t_bt_find_smallest(t->right);  

    if(!left && !right) return t;
    else
    {
        if(left->data <= right->data) smallest = left;
        else smallest = right;
    }

    if(t->data <= smallest->data) return t;
    else return smallest;
}

/*
=============================================
            insert Methods
=============================================
*/

t_bt *t_bt_insert(int new_data, t_bt *l, t_bt *r)
{
    t_bt *new_node  = (t_bt *) malloc(sizeof(t_bt));
    new_node->data  = new_data;
    new_node->left  = l;
    new_node->right = r;
    return (new_node);
}

t_bt *t_bt_insert_left_unsafe(t_bt *t, t_bt *parent_node, int new_node_data)
{
    t_bt *new_node = t_bt_insert(new_node_data, NULL, NULL);
    parent_node->left = new_node;
    return (t);
}

t_bt *t_bt_insert_left_safe(t_bt *t, t_bt *parent_node, int new_node_data)
{
    if(!parent_node->left){
        t_bt *new_node = t_bt_insert(new_node_data, NULL, NULL);
        parent_node->left = new_node;
    }
    return (t);
}

t_bt *t_bt_insert_right_unsafe(t_bt *t, t_bt *parent_node, int new_node_data)
{
    t_bt *new_node = t_bt_insert(new_node_data, NULL, NULL);
    parent_node->right = new_node;
    return (t);
}

t_bt *t_bt_insert_right_safe(t_bt *t, t_bt *parent_node, int new_node_data)
{
    if(!parent_node->right){
        t_bt *new_node = t_bt_insert(new_node_data, NULL, NULL);
        parent_node->right = new_node;
    }
    return (t);
}

/*
=============================================
            print Methods
=============================================
*/

void t_bt_print_pre(t_bt *t)
{
    if(t)
    {
        printf("%d ", t->data);
        t_bt_print_pre(t->left);
        t_bt_print_pre(t->right);
    }
}

void t_bt_print_in(t_bt *t)
{
    if(t)
    {
        t_bt_print_in(t->left);
        printf("%d ", t->data);
        t_bt_print_in(t->right);
    }
}

void t_bt_print_pos(t_bt *t)
{
    if(t)
    {
        t_bt_print_pos(t->left);
        printf("%d ", t->data);
        t_bt_print_pos(t->right);
    }
}