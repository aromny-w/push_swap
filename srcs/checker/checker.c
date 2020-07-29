/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:04:39 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/29 20:37:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute(t_stk **a, t_stk **b, int fd, int vis)
{
	char	*line;

	line = NULL;
	if (!(*a)->head)
		do_exit(-1);
	if (vis == 1)
		visualize(*a, *b, fd);
	else
		while (get_next_line(fd, &line) == 1)
			do_op(line, a, b);
}

void		checker(char **input, int fd, int vis)
{
	t_stk	*a;
	t_stk	*b;

	initstacks(&a, &b);
	while (*input)
	{
		if (!ft_strcmp(*input, "-v"))
			vis = 1;
		else if (!(fd > 0) && (fd = open(*input, O_RDONLY)) > 0)
			;
		else
			setarg(*input, a);
		input++;
	}
	setpos(&a->head);
	execute(&a, &b, fd == -1 ? 0 : fd, vis);
	if (!is_sorted(a->head) || b->head)
		do_exit(EXIT_FAILURE);
	do_exit(EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		checker(++argv, 0, 0);
	return (0);
}
