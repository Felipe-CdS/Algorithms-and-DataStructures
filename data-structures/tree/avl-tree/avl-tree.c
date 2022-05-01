#include "avl-tree.h"

/*==========================================*/
/*		Standard Methods Implementation		*/
/*==========================================*/

t_avlt	*init_tree	(void)
{
    return NULL;
}

void	free_tree	(t_avlt *t)
{
	if(t)
	{
		free_tree(t->left);
		free_tree(t->right);
		free(t);
	}
}

t_avlt	*search		(t_avlt *t, int x)
{
	return NULL;
}

void	print		(t_avlt *t)
{
	printf("Print Method");
}

/*==========================================*/
/*		Insert/Remove Implementation		*/
/*==========================================*/

t_avlt	*create_node	(t_avlt *t, int x, t_avlt *left, t_avlt *right)
{
	t_avlt *new_node;

	new_node = (t_avlt *) malloc(sizeof(t_avlt));
	new_node->data	= x;
	new_node->left	= left;
	new_node->right	= right;

	return new_node;
}

t_avlt	*insert			(t_avlt *t, int x)
{
	return NULL;
}

void	remove_node		(t_avlt *t, int x)
{

}
