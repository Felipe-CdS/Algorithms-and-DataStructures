#include <stdio.h>
#include <stdlib.h>

typedef struct	s_avltree {
	int	data;
	struct	s_avltree *left;
	struct	s_avltree *right;
} t_avlt;

/*==================================*/
/*			Standard Methods		*/
/*==================================*/

t_avlt	*init_tree			(void);
t_avlt	*search				(t_avlt *t, int x);
void	free_tree			(t_avlt *t);
void	print				(t_avlt *t);

/*==================================*/
/*		Insert/Remove Methods		*/
/*==================================*/

t_avlt	*create_node		(t_avlt *t, int x, t_avlt *left, t_avlt *right);
t_avlt	*insert				(t_avlt *t, int x);
void	remove_node			(t_avlt *t, int x);

/*==================================*/
/*			Rotate Methods			*/
/*==================================*/

t_avlt	*rotate_left_left	(t_avlt *t);
t_avlt	*rotate_right_right	(t_avlt *t);
t_avlt	*rotate_left_right	(t_avlt *t);
t_avlt	*rotate_right_left	(t_avlt *t);