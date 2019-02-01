/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:30:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/01 22:01:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int get_min(t_stack *stack)
{
	int index;
	int min;

	index = 0;
	min = 0;
	while (++index < stack->size_a)
		if (stack->a[index] < stack->a[min])
			min = index;
	return (min);
}

void	ft_sort3(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
	{
		ft_puts("sa");
		ft_sa(stack);
	}
	if (stack->size_a > 2 && stack->a[1] > stack->a[2])
	{
		ft_puts("rra");
		ft_rra(stack);
	}
	if (stack->a[0] > stack->a[1])
	{
		ft_puts("sa");
		ft_sa(stack);
	}
}

int	sort1(t_stack *stack)
{
	int min;

	while (stack->size_a > 4)
	{
		min = get_min(stack);
		if (min < (stack->size_a / 2.0))
		{
			while (--min >= 0)
			{
				ft_puts("ra");
				ft_ra(stack);
			}
		}
		else
		{
			min = stack->size_a - min;
			while (--min >= 0)
			{
				ft_puts("rra");
				ft_rra(stack);
			}
		}
		ft_puts("pb");
		ft_pb(stack);
	}
	ft_sort3(stack);
	while (stack->size_b > 0)
	{
		ft_puts("pa");
		ft_pa(stack);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_stack *stack;

	if (argc > 1)
	{
		if (!ft_check_arg(argc - 1, argv + 1))
			EXIT();
		if ((stack = ft_init_stack(argc - 1, (argv + 1))) == NULL)
			EXIT();
		sort1(stack);
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return (0);
}