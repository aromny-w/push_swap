/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setparts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:57:04 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/02 21:57:06 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	setparts(t_arg **arg, size_t size)
{
	t_arg	*tmp;
	size_t	i;

	tmp = *arg;
	i = 0;
	while (tmp)
	{
		if (++i * 2 <= size + 1)
			tmp->part = 1;
		else
			tmp->part = 2;
		tmp = tmp->next;
	}
	return (1);
}
