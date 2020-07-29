/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:02:04 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/28 14:34:00 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort(t_stk *a, t_stk *b, t_piv pivot)
{
	while (b->size != pivot.value && !is_sorted(a->head))
	{
		if (a->head->pos <= pivot.value)
		{
			do_op(putop("pb"), &a, &b);
			if (b->head && b->head != b->tail && b->head->pos < pivot.pivot &&
				b->head->next->pos >= pivot.pivot)
				do_op(putop("rb"), &a, &b);
		}
		else
			do_op(putop("ra"), &a, &b);
	}
}

static t_piv	getpivot(t_arg *arg, size_t min, size_t max)
{
	t_piv	pivot;

	while ((arg = arg->next))
	{
		if (min > arg->pos)
			min = arg->pos;
		if (max < arg->pos)
			max = arg->pos;
	}
	pivot.min = min;
	pivot.max = max;
	pivot.value = (pivot.min + pivot.max) / 2;
	pivot.pivot = pivot.min + (pivot.value - pivot.min + 1) / 2;
	return (pivot);
}

void			phase_0(t_stk *a, t_stk *b)
{
	t_piv	pivot;

	pivot = getpivot(a->head, a->head->pos, a->head->pos);
	sort(a, b, pivot);
}
