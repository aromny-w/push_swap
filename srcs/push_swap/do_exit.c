/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:46:54 by aromny-w          #+#    #+#             */
/*   Updated: 2019/07/01 20:46:55 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_exit(int status)
{
	if (status == 1)
		ft_putendl_fd("OK", 1);
	else if (status == 0)
		ft_putendl_fd("KO", 1);
	else if (status == -1)
		ft_putendl_fd("Error", 2);
	if (status != -1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (1);
}
