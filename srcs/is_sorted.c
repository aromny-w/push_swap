/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:19:55 by aromny-w          #+#    #+#             */
/*   Updated: 2019/07/29 21:19:57 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_arg *arg)
{
	if (arg && arg->next)
		while (arg->next && arg->pos + 1 == arg->next->pos)
			arg = arg->next;
	if (arg->next)
		return (0);
	return (1);
}
