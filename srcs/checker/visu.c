/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 20:58:21 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/29 22:07:29 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		close_win(t_mlx *info)
{
	mlx_destroy_image(info->mlx_ptr, info->img_ptr);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	close(info->fd);
	if (!is_sorted(info->a->head) || info->b->head)
		return (do_exit(EXIT_SUCCESS));
	return (do_exit(EXIT_FAILURE));
}

static int		exit_key(int key, t_mlx *info)
{
	if (key == 53)
		close_win(info);
	return (0);
}

static int		visual_hook(t_mlx *info)
{
	char	*line;

	line = NULL;
	draw(info);
	if (get_next_line(info->fd, &line) == 1)
	{
		do_op(line, &info->a, &info->b);
		free(line);
	}
	return (1);
}

static size_t	getmaxvalue(t_arg *arg)
{
	int	max;

	max = arg->value;
	while ((arg = arg->next))
		if (max < (arg->value < 0 ? -(long)arg->value : arg->value))
			max = arg->value < 0 ? -(long)arg->value : arg->value;
	return (max);
}

void			visualize(t_stk *a, t_stk *b, int fd)
{
	t_mlx	info;

	info.a = a;
	info.b = b;
	info.fd = fd;
	init_mlx(&info);
	info.arg_max = getmaxvalue(a->head);
	info.arg_height = info.height / a->size;
	mlx_key_hook(info.win_ptr, exit_key, &info);
	mlx_loop_hook(info.mlx_ptr, visual_hook, &info);
	mlx_hook(info.win_ptr, 17, 1L << 17, close_win, &info);
	mlx_loop(info.mlx_ptr);
}
