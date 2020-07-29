/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:13:57 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/28 15:17:24 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_piv	getpivot(t_arg *head, t_arg *tail, size_t size, size_t sum)
{
	t_piv	pivot;
	t_arg	*arg;
	size_t	i;

	i = size;
	pivot.min = head->pos > tail->pos ? head->pos : tail->pos;
	pivot.max = head->pos > tail->pos ? head->pos : tail->pos;
	while ((arg = head->pos > tail->pos ? head : tail))
	{
		sum += arg->pos;
		if (pivot.min > arg->pos)
			pivot.min = arg->pos;
		if (pivot.max < arg->pos)
			pivot.max = arg->pos;
		if (sum == size)
			break ;
		size += --i;
		if (head->pos > tail->pos)
			head = head->next;
		else
			tail = tail->prev;
	}
	pivot.value = (pivot.min + pivot.max) / 2;
	pivot.pivot = pivot.min + (pivot.value - pivot.min + 1) / 2;
	return (pivot);
}

void			phase_2(t_stk *a, t_stk *b)
{
	t_piv	pivot;

	if (is_sorted(a->head) && !b->head)
		return ;
	setparts(&b->head, b->size);
	setdistance(&b->head, b->size);
	pivot = getpivot(b->head, b->tail, b->size, 0);
	if (pivot.max - pivot.min + 1 <= 50)
		insertionsort(a, b, pivot, pivot.max - pivot.min + 1);
	else
		phase_3(a, b, pivot);
	phase_2(a, b);
}
