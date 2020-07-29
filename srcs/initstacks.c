/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:24:51 by aromny-w          #+#    #+#             */
/*   Updated: 2019/07/29 21:24:52 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initstacks(t_stk **a, t_stk **b)
{
	if (!(*a = (t_stk *)malloc(sizeof(t_stk))))
		do_exit(-1);
	(*a)->head = NULL;
	(*a)->tail = NULL;
	(*a)->size = 0;
	if (!(*b = (t_stk *)malloc(sizeof(t_stk))))
		do_exit(-1);
	(*b)->head = NULL;
	(*b)->tail = NULL;
	(*b)->size = 0;
}
