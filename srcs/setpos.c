/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:45:35 by aromny-w          #+#    #+#             */
/*   Updated: 2019/07/11 14:45:37 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	getpos(int value, t_arg *arg)
{
	size_t	pos;

	pos = 1;
	while (arg)
	{
		if (arg->value < value)
			pos++;
		arg = arg->next;
	}
	return (pos);
}

int				setpos(t_arg **arg)
{
	t_arg	*tmp;

	tmp = *arg;
	while (tmp)
	{
		tmp->pos = getpos(tmp->value, *arg);
		tmp = tmp->next;
	}
	return (1);
}
