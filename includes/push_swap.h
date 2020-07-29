/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:30:46 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/29 21:12:58 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

# define BLACK 0x000000
# define WHITE 0xffffff
# define MAROON 0x800000
# define GREEN 0x008000

typedef struct	s_vec
{
	char	*value;
	double	n;
	double	t;
}				t_vec;

typedef struct	s_piv
{
	size_t	value;
	size_t	min;
	size_t	max;
	size_t	pivot;
}				t_piv;

typedef struct	s_arg
{
	int				value;
	size_t			part;
	size_t			pos;
	size_t			dist;
	struct s_arg	*prev;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_stk
{
	t_arg	*head;
	t_arg	*tail;
	size_t	size;
}				t_stk;

typedef struct	s_mlx
{
	t_stk	*a;
	t_stk	*b;
	size_t	height;
	size_t	width;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	size_t	arg_max;
	size_t	arg_width;
	size_t	arg_height;
}				t_mlx;

void			checker(char **input, int fd, int vis);
void			push_swap(char **input);
void			initstacks(t_stk **a, t_stk **b);
void			setarg(char *input, t_stk *a);
int				setgroup(t_arg **head_a, t_arg **head_b);
int				setpos(t_arg **arg);
int				setparts(t_arg **arg, size_t size);
int				setdistance(t_arg **arg, size_t size);
t_vec			getvec(t_arg *arg, t_piv pivot, size_t n);
void			phase_0(t_stk *a, t_stk *b);
void			phase_1(t_stk *a, t_stk *b);
void			phase_2(t_stk *a, t_stk *b);
void			phase_3(t_stk *a, t_stk *b, t_piv pivot);
void			insertionsort(t_stk *a, t_stk *b, t_piv pivot, size_t n);
char			*putop(char *op);
int				is_sorted(t_arg *arg);
int				do_op(char *op, t_stk **a, t_stk **b);
int				do_exit(int status);
void			init_mlx(t_mlx *info);
void			visualize(t_stk *a, t_stk *b, int fd);
void			draw(t_mlx *info);

#endif
