/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:27:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 07:21:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_to_b(t_stack *stack, int size);

static void	ft_to_a(t_stack *stack, int size)
{
	if (size <= 3)
		return ;
	int		index;
	float	mid;
	int		temp;
	int		start;

	start = size;
	if (size <= 1)
		return ;
	index = -1;
	mid = 0;
	while (++index < size)
		mid += stack->b[index];
	mid = mid / (float)(size);
	index = -1;
	temp = size;
	while (++index < size)
	{
		if (stack->b[0] > mid)
		{
			ft_puts("pa");
			ft_pa(stack);
			temp--;
		}
		else
		{
			ft_puts("rb");
			ft_rb(stack);
		}
	}
	size = temp;
	if (size != stack->size_b)
	{
		index = -1;
		while (++index < size)
		{
			ft_puts("rrb");
			ft_rrb(stack);
		}
	}
	index = -1;
	while (++index < size)
	{
		ft_puts("pa");
		ft_pa(stack);
	}
	size = start - temp;
	ft_to_a(stack, size);
	ft_to_a(stack, temp);
}

static void	ft_to_b(t_stack *stack, int size)
{
	int		index;
	float	mid;
	int		temp;
	int		start;

	if (size <= 3)
		return ;
	start = size;
	if (size <= 1)
		return ;
	index = -1;
	mid = 0;
	while (++index < size)
		mid += stack->a[index];
	mid = mid / (float)(size);
	index = -1;
	temp = size;
	while (++index < size)
	{
		if (stack->a[0] < mid)
		{
			ft_puts("pb");
			ft_pb(stack);
			temp--;
		}
		else
		{
			ft_puts("ra");
			ft_ra(stack);
		}
	}
	size = temp;
	if (size != stack->size_a)
	{
		index = -1;
		while (++index < size)
		{
			ft_puts("rra");
			ft_rra(stack);
		}
	}
	index = -1;
	while (++index < size)
	{
		ft_puts("pb");
		ft_pb(stack);
	}
	size = start - temp;
	ft_to_a(stack, size);
	ft_to_a(stack, temp);
}

int			sort2(t_stack *stack)
{
	ft_to_b(stack, stack->size_a);
	return (0);
}
