/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:25:31 by aromny-w          #+#    #+#             */
/*   Updated: 2019/06/30 17:25:32 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_duplicate(int value, t_arg *arg)
{
	while (arg && arg->next)
	{
		if (arg->value == value)
			return (1);
		arg = arg->next;
	}
	return (0);
}

static t_arg	*argnew(int value, t_arg *prev)
{
	t_arg	*arg;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		do_exit(-1);
	arg->value = value;
	arg->prev = prev;
	arg->next = NULL;
	return (arg);
}

static int		getvalue(char **str)
{
	long	n;
	int		sign;

	while (ft_isspace(**str))
		(*str)++;
	sign = 1;
	if (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			sign = -1;
	n = 0;
	if (ft_isdigit(**str))
		while (ft_isdigit(**str))
		{
			n = 10 * n + (*(*str)++ - '0');
			if ((sign == 1 && n > INT_MAX) ||
				(sign == -1 && n > -(long)INT_MIN))
				do_exit(-1);
		}
	else
		do_exit(-1);
	return ((int)n * sign);
}

void			setarg(char *input, t_stk *a)
{
	if (!a->head)
	{
		a->head = argnew(getvalue(&input), NULL);
		a->tail = a->head;
		a->size = 1;
	}
	while (*input)
	{
		a->tail->next = argnew(getvalue(&input), a->tail);
		a->tail = a->tail->next;
		a->size++;
		if (is_duplicate(a->tail->value, a->head))
			do_exit(-1);
	}
}
