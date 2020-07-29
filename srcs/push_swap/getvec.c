/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:21:53 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/19 15:21:54 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_arg	*getedge(t_arg *arg, size_t value)
{
	while (arg && arg->pos != value)
		arg = arg->next;
	return (arg);
}

static void		initedges(t_arg *arg, t_arg **edge, t_piv pivot, size_t n)
{
	edge[0] = getedge(arg, pivot.max);
	edge[1] = n > 1 ? getedge(arg, pivot.min) : NULL;
	edge[2] = n > 2 ? getedge(arg, pivot.max - 1) : NULL;
	edge[3] = n > 3 ? getedge(arg, pivot.min + 1) : NULL;
	edge[1] ? edge[1]->dist += 1 : 0;
	edge[2] ? edge[2]->dist += 2 : 0;
	edge[3] ? edge[3]->dist += 3 : 0;
}

static void		initvec(t_vec *vec)
{
	vec[0].value = "rb";
	vec[0].n = 0;
	vec[0].t = 0;
	vec[1].value = "rrb";
	vec[1].n = 0;
	vec[1].t = 0;
}

t_vec			getvec(t_arg *arg, t_piv pivot, size_t n)
{
	t_vec	vec[2];
	t_arg	*edge[4];
	size_t	i;

	initvec(vec);
	initedges(arg, edge, pivot, n);
	i = 0;
	while (i < 4)
	{
		if (edge[i] && edge[i]->part == 1 && ++vec[0].n)
			vec[0].t = edge[i]->dist > vec[0].t ? edge[i]->dist : vec[0].t;
		else if (edge[i] && edge[i]->part == 2 && ++vec[1].n)
			vec[1].t = edge[i]->dist > vec[1].t ? edge[i]->dist : vec[1].t;
		i++;
	}
	if (!vec[0].t || !vec[1].t)
		return (!vec[1].t ? vec[0] : vec[1]);
	return ((vec[0].n / vec[0].t) > (vec[1].n / vec[1].t) ? vec[0] : vec[1]);
}
