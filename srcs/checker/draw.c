/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:36:06 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/29 21:03:09 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_labs(long i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static void	draw_stack_a(t_arg *arg, t_mlx *info, size_t line)
{
	size_t	offset;
	size_t	i;
	size_t	j;

	while (arg)
	{
		info->arg_width = info->width / 2 * ft_labs(arg->value) / info->arg_max;
		offset = (info->width / 2 - info->arg_width) / 2;
		i = -1;
		while (++i < info->arg_height)
		{
			j = -1;
			while (++j < info->arg_width)
			{
				if (arg->value > 0)
					info->data[line * info->width + j + offset] = GREEN;
				else
					info->data[line * info->width + j + offset] = MAROON;
			}
			line--;
		}
		arg = arg->prev;
	}
}

static void	draw_stack_b(t_arg *arg, t_mlx *info, size_t line)
{
	size_t	offset;
	size_t	i;
	size_t	j;

	while (arg)
	{
		info->arg_width = info->width / 2 * ft_labs(arg->value) / info->arg_max;
		offset = info->width / 2 + (info->width / 2 - info->arg_width) / 2;
		i = -1;
		while (++i < info->arg_height)
		{
			j = -1;
			while (++j < info->arg_width)
			{
				if (arg->value > 0)
					info->data[line * info->width + j + offset] = GREEN;
				else
					info->data[line * info->width + j + offset] = MAROON;
			}
			line--;
		}
		arg = arg->prev;
	}
}

static void	draw_background(t_mlx *info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if (j < info->width / 2)
				info->data[i * info->width + j] = WHITE;
			else
				info->data[i * info->width + j] = BLACK;
		}
	}
}

void		draw(t_mlx *info)
{
	draw_background(info);
	draw_stack_a(info->a->tail, info, info->height - 1);
	draw_stack_b(info->b->tail, info, info->height - 1);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
}
