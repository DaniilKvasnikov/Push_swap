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
			ft_ra(stack, 1);
		else if (max == 1)
			ft_rra(stack, 1);
	}
	if (stack->a[0] > stack->a[1])
		ft_sa(stack, 1);
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
				ft_ra(stack, 1);
		}
		else
		{
			min = stack->size_a - min;
			while (--min >= 0)
				ft_rra(stack, 1);
		}
		ft_pb(stack, 1);
	}
}

int			sort1(t_stack *stack)
{
	ft_sort(stack);
	ft_sort3(stack);
	while (stack->size_b > 0)
		ft_pa(stack, 1);
	return (0);
}
