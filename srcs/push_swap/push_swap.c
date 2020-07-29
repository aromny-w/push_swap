/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:40:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/28 15:00:57 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_for_3(t_stk *a, t_stk *b)
{
	while (!is_sorted(a->head))
	{
		if (a->head->pos == a->head->next->pos + 1)
			do_op(putop("sa"), &a, &b);
		if (a->head->pos == a->tail->pos + 1 &&
		(a->tail->pos == a->tail->prev->pos + 1 ||
		a->head->pos + 1 == a->head->next->pos))
		{
			if (a->tail->pos == a->tail->prev->pos + 1)
				do_op(putop("ra"), &a, &b);
			else if (a->head->pos + 1 == a->head->next->pos)
				do_op(putop("rra"), &a, &b);
		}
		if (a->head->pos + 1 == a->tail->pos)
		{
			do_op(putop("rra"), &a, &b);
			do_op(putop("sa"), &a, &b);
		}
	}
}

static void	sort(t_stk *a, t_stk *b)
{
	phase_0(a, b);
	phase_1(a, b);
	phase_2(a, b);
}

void		push_swap(char **input)
{
	t_stk	*a;
	t_stk	*b;

	initstacks(&a, &b);
	while (*input)
		setarg(*input++, a);
	setpos(&a->head);
	if (a->size == 3)
		case_for_3(a, b);
	else
		sort(a, b);
	do_exit(2);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(++argv);
	return (0);
}
