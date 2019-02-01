/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:27:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 01:01:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_min(t_stack *stack)
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

static int	get_max(t_stack *stack)
{
	int index;
	int max;

	index = 0;
	max = 0;
	while (++index < stack->size_a)
		if (stack->a[index] > stack->a[max])
			max = index;
	return (max);
}

static void	ft_sort3(t_stack *stack)
{
	int	max;

	max = get_max(stack);
	if (stack->size_a > 2)
	{
		if (max == 0)
		{
			ft_puts("ra");
			ft_ra(stack);
		}
		else if (max == 1)
		{
			ft_puts("rra");
			ft_rra(stack);
		}
	}
	if (stack->a[0] > stack->a[1])
	{
		ft_puts("sa");
		ft_sa(stack);
	}
}

static void	ft_sort(t_stack *stack)
{
	int min;

	while (stack->size_a > 3)
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
}

int			sort1(t_stack *stack)
{
	ft_sort(stack);
	ft_sort3(stack);
	while (stack->size_b > 0)
	{
		ft_puts("pa");
		ft_pa(stack);
	}
	return (0);
}
