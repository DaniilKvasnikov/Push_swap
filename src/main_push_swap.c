/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:30:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 05:42:32 by rrhaenys         ###   ########.fr       */
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

static char	**ft_oneparam(char *str, int *argc)
{
	char	**argv;

	argv = ft_strsplit(str, ' ');
	*argc = 0;
	while (argv[++(*argc)] != NULL)
		;
	return (argv);
}

int			main(int argc, char **argv)
{
	t_stack *stack;
	int		clear;

	if (argc < 2)
		NOARGP();
	++argv;
	--argc;
	clear = (argc == 1);
	if (argc == 1)
		argv = ft_oneparam(argv[0], &argc);
	if (!ft_check_arg(argc, argv) ||
		((stack = ft_init_stack(argc, argv)) == NULL))
		EXIT();
	if (ft_is_sort(stack) == 1)
		return (ft_free_stack(stack, clear, argv));
	stack->str = ft_strdup("");
	if (stack->size_a >= 10)
		sort2(stack);
	else
		sort1(stack);
	ft_printf("%s", stack->str);
	free(stack->str);
	return (ft_free_stack(stack, clear, argv));
}
