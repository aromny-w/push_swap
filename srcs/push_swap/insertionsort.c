/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:04:49 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/28 15:17:20 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swapcheck(t_stk *a, t_stk *b)
{
	if (a->head && a->head->next)
		if (a->head->pos == a->head->next->pos + 1 || (a->head->next->next &&
			a->head->pos == a->head->next->next->pos + 1))
			do_op(putop("sa"), &a, &b);
}

static void		mergeparts(t_stk *a, t_stk *b)
{
	while (a->tail->pos != a->size + b->size)
	{
		do_op(putop("rra"), &a, &b);
		swapcheck(a, b);
	}
}

static void		pivotmod(t_stk *a, t_stk *b, t_piv *pivot)
{
	if (a->head->pos == pivot->max && pivot->max > pivot->min)
	{
		pivot->max--;
		if (a->head->next->pos == pivot->max && pivot->max > pivot->min)
			pivot->max--;
	}
	if ((a->head->pos == pivot->min || a->head->pos - 1 == pivot->min) &&
		pivot->max > pivot->min)
		do_op(putop("ra"), &a, &b);
	if (a->tail->pos == pivot->min && pivot->min < pivot->max)
	{
		pivot->min++;
		if (a->tail->prev->pos == pivot->min && pivot->min < pivot->max)
			pivot->min++;
	}
}

static int		push_case(t_stk *a, t_stk *b, t_piv *pivot)
{
	if (b->size == 1)
		do_op(putop("pa"), &a, &b);
	else if ((b->head->pos == pivot->max || b->head->pos + 1 == pivot->max) &&
			(b->head->pos >= pivot->min && b->head->pos <= pivot->max))
		do_op(putop("pa"), &a, &b);
	else if ((b->head->pos == pivot->min || b->head->pos - 1 == pivot->min) &&
			(b->head->pos >= pivot->min && b->head->pos <= pivot->max))
		do_op(putop("pa"), &a, &b);
	else
		return (0);
	pivotmod(a, b, pivot);
	return (1);
}

void			insertionsort(t_stk *a, t_stk *b, t_piv pivot, size_t n)
{
	t_vec	vec;

	setparts(&b->head, b->size);
	setdistance(&b->head, b->size);
	vec = getvec(b->head, pivot, pivot.max - pivot.min + 1);
	while (vec.n)
	{
		if (push_case(a, b, &pivot) && n--)
			vec.n--;
		else
			do_op(putop(vec.value), &a, &b);
		swapcheck(a, b);
	}
	if (!n)
		mergeparts(a, b);
	else
		insertionsort(a, b, pivot, n);
}
