/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:11:01 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/17 19:11:03 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushall(t_stk *a, t_stk *b, t_piv *pivot)
{
	size_t	i;

	pivot->min = 1;
	pivot->max = b->size;
	pivot->value = (pivot->min + pivot->max) / 2;
	pivot->pivot = pivot->min + (pivot->value - pivot->min + 1) / 2;
	i = pivot->max - pivot->value + 1;
	while (i)
	{
		if (b->head->pos >= pivot->value && i--)
			do_op(putop("pa"), &a, &b);
		else if (b->head->pos < pivot->value)
			do_op(putop("rb"), &a, &b);
	}
}

static void	pushtail(t_stk *a, t_stk *b, t_piv pivot)
{
	while (b->tail->pos >= pivot.min && b->tail->pos <= pivot.max)
	{
		if (b->tail->pos >= pivot.value)
		{
			do_op(putop("rrb"), &a, &b);
			do_op(putop("pa"), &a, &b);
		}
		else if (b->tail->pos < pivot.value)
			do_op(putop("rrb"), &a, &b);
	}
}

static void	pushhead(t_stk *a, t_stk *b, t_piv pivot)
{
	while (b->head->pos >= pivot.min && b->head->pos <= pivot.max)
	{
		if (b->head->pos >= pivot.value)
			do_op(putop("pa"), &a, &b);
		else if (b->head->pos < pivot.value)
			do_op(putop("rb"), &a, &b);
	}
}

static void	sort(t_stk *a, t_stk *b, t_piv pivot)
{
	pivot.pivot = pivot.value + (pivot.max - pivot.value + 1) / 2;
	while (!is_sorted(a->head) && a->head->pos >= pivot.min &&
	a->head->pos <= pivot.max)
	{
		if (a->head->pos <= pivot.max)
			do_op(putop("pb"), &a, &b);
		if (b->head && b->head != b->tail && b->head->pos > pivot.pivot &&
			b->head->next->pos <= pivot.pivot)
			do_op(putop("rb"), &a, &b);
	}
}

void		phase_3(t_stk *a, t_stk *b, t_piv pivot)
{
	if (b->head->pos >= pivot.min && b->head->pos <= pivot.max &&
		!(b->tail->pos >= pivot.min && b->tail->pos <= pivot.max))
		pushhead(a, b, pivot);
	else if ((b->tail->pos >= pivot.min && b->tail->pos <= pivot.max) &&
			!(b->head->pos >= pivot.min && b->head->pos <= pivot.max))
		pushtail(a, b, pivot);
	else
		pushall(a, b, &pivot);
	sort(a, b, pivot);
}
