/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:29:22 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/29 18:29:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_window(t_mlx *info, int width, int height, char *name)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	if (!(info->win_ptr = mlx_new_window(info->mlx_ptr, width, height, name)))
		do_exit(EXIT_FAILURE);
	if (!(info->img_ptr = mlx_new_image(info->mlx_ptr, width, height)))
	{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		do_exit(EXIT_FAILURE);
	}
	if (!(info->data = (int *)mlx_get_data_addr(info->img_ptr, &bits_per_pixel,
	&size_line, &endian)))
	{
		mlx_destroy_image(info->mlx_ptr, info->img_ptr);
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		do_exit(EXIT_FAILURE);
	}
}

static void	set_resolution(t_mlx *info)
{
	info->width = info->a->size;
	info->height = 1000;
	while (info->width + info->a->size <= 2000)
		info->width += info->a->size;
	while (info->height % info->a->size)
		info->height--;
}

void		init_mlx(t_mlx *info)
{
	set_resolution(info);
	if (!(info->mlx_ptr = mlx_init()))
		do_exit(EXIT_FAILURE);
	init_window(info, info->width, info->height, "push_swap");
}
