/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdistance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:41:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/08/01 17:41:17 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	setdistance(t_arg **arg, size_t size)
{
	t_arg	*tmp;
	size_t	dist;

	tmp = *arg;
	dist = 1;
	while (tmp)
	{
		if (dist * 2 <= size + 1)
			tmp->dist = dist++;
		else
			tmp->dist = (size + 1 - dist++) + 1;
		tmp = tmp->next;
	}
	return (1);
}
