/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:46:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/27 20:12:58 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_reverse_rotate(t_stk **stack)
{
	t_arg	*tmp;

	if ((*stack)->head && (*stack)->head->next)
	{
		tmp = (*stack)->tail->prev;
		(*stack)->tail = (*stack)->tail->prev;
		tmp->next->next = (*stack)->head;
		(*stack)->head = tmp->next;
		tmp->next = NULL;
		(*stack)->head->prev = NULL;
		(*stack)->head->next->prev = (*stack)->head;
	}
	return (1);
}

static int	do_rotate(t_stk **stack)
{
	t_arg	*tmp;

	if ((*stack)->head && (*stack)->head->next)
	{
		tmp = (*stack)->tail;
		tmp->next = (*stack)->head;
		(*stack)->head = (*stack)->head->next;
		tmp->next->next = NULL;
		(*stack)->head->prev = NULL;
		if ((*stack)->tail->next)
		{
			(*stack)->tail->next->prev = (*stack)->tail;
			(*stack)->tail = (*stack)->tail->next;
		}
	}
	return (1);
}

static int	do_push(t_stk **dst, t_stk **src)
{
	t_arg	*tmp;

	if ((*src)->head)
	{
		tmp = (*src)->head;
		(*src)->head = (*src)->head->next;
		if ((*src)->head)
			(*src)->head->prev = NULL;
		else
			(*src)->tail = NULL;
		tmp->next = (*dst)->head;
		(*dst)->head = tmp;
		if ((*dst)->head->next)
			(*dst)->head->next->prev = (*dst)->head;
		else
			(*dst)->tail = (*dst)->head;
		(*src)->size--;
		(*dst)->size++;
	}
	return (1);
}

static int	do_swap(t_stk **stack)
{
	t_arg	*tmp;

	if ((*stack)->head && (*stack)->head->next)
	{
		tmp = (*stack)->head;
		(*stack)->head = (*stack)->head->next;
		(*stack)->head->prev = NULL;
		tmp->prev = (*stack)->head;
		if ((*stack)->head->next)
			(*stack)->head->next->prev = tmp;
		tmp->next = (*stack)->head->next;
		(*stack)->head->next = tmp;
		if ((*stack)->tail->next)
			(*stack)->tail = (*stack)->head->next;
	}
	return (1);
}

int			do_op(char *op, t_stk **a, t_stk **b)
{
	if (!ft_strcmp(op, "sa"))
		return (do_swap(a));
	if (!ft_strcmp(op, "sb"))
		return (do_swap(b));
	if (!ft_strcmp(op, "ss"))
		return (do_swap(a) && do_swap(b));
	if (!ft_strcmp(op, "pa"))
		return (do_push(a, b));
	if (!ft_strcmp(op, "pb"))
		return (do_push(b, a));
	if (!ft_strcmp(op, "ra"))
		return (do_rotate(a));
	if (!ft_strcmp(op, "rb"))
		return (do_rotate(b));
	if (!ft_strcmp(op, "rr"))
		return (do_rotate(a) && do_rotate(b));
	if (!ft_strcmp(op, "rra"))
		return (do_reverse_rotate(a));
	if (!ft_strcmp(op, "rrb"))
		return (do_reverse_rotate(b));
	if (!ft_strcmp(op, "rrr"))
		return (do_reverse_rotate(a) && do_reverse_rotate(b));
	return (do_exit(-1));
}
