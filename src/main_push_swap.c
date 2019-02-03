/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:30:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 07:38:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_is_sort(t_stack *stack)
{
	int	index;

	if (stack->size_b != 0)
		return (0);
	index = -1;
	while (++index < (stack->size_a - 1))
		if (stack->a[index] > stack->a[index + 1])
			return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack *stack;
	int		clear;

	clear = 0;
	if (argc < 2)
		NOARGP();
	++argv;
	--argc;
	if (argc == 1)
	{
		clear = 1;
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv[argc] != NULL)
			++argc;
	}
	if (!ft_check_arg(argc, argv))
		EXIT();
	if ((stack = ft_init_stack(argc, argv)) == NULL)
		EXIT();
	if (ft_is_sort(stack) == 1)
		return (ft_free_stack(stack, clear, argv));
	if (stack->size_a >= 10)
		sort2(stack);
//	sort1(stack);
	return (ft_free_stack(stack, clear, argv));
}
