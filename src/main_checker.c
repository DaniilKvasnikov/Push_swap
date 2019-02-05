/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:29:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 11:39:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_is_sort(t_stack *stack)
{
	int	index;

	if (stack->size_b != 0)
	{
		ft_puts("\x1b[31mKO\033[0m");
		return (0);
	}
	index = -1;
	while (++index < (stack->size_a - 1))
		if (stack->a[index] > stack->a[index + 1])
		{
			ft_puts("\x1b[31mKO\033[0m");
			return (0);
		}
	ft_puts("\x1b[32mOK\033[0m");
	return (1);
}

static int	ft_will_print(char *str)
{
	if (!ft_strcmp(str, "-c"))
		return (1);
	if (!ft_strcmp(str, "-v"))
		return (2);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack *stack;
	int		print;
	int		clear;

	if (argc < 2)
		NOARGCH();
	print = ft_will_print(*(++argv));
	argc = argc - 1 - (print > 0);
	argv += (print > 0);
	if (argc < 1)
		NOARGCH();
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = -1;
		while (argv[++argc] != NULL)
			clear = 1;
	}
	if (!ft_check_arg(argc, argv) ||
	((stack = ft_init_stack(argc, argv)) == NULL))
		EXIT();
	ft_print_stack(stack, print, 0);
	if (!ft_body_checker(stack, print))
		ft_is_sort(stack);
	return (ft_free_stack(stack, clear, argv));
}
