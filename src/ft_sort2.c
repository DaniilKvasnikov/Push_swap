/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:27:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 05:15:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_to_b(t_stack *stack, int size)
{
	int		index;
	float	mid;
	int		len;

	index = -1;
	mid = 0;
	while (++index < size)
		mid += stack->a[index];
	mid = mid / (float)(size);
	index = -1;
	len = 0;
	while (++index < size)
	{
		if (stack->a[0] <= mid)
		{
			ft_pb(stack, 1);
			len++;
		}
		else
			ft_ra(stack, 1);
	}
	return (len);
}

static void	ft_sort_a(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, 1);
		return ;
	}
	if (ft_cmp_stack(stack, 0, 1, 2) == 1)
		ft_sa(stack, 1);
	if (ft_cmp_stack(stack, 0, 2, 1) == 1)
		ft_sa(stack, 1);
	if ((ft_cmp_stack(stack, 1, 2, 0) == 1) ||
		(ft_cmp_stack(stack, 1, 0, 2) == 1))
	{
		ft_ra(stack, 1);
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	if (ft_cmp_stack(stack, 2, 0, 1) == 1)
		ft_sa(stack, 1);
}

static int	ft_resort(t_stack *stack, int size)
{
	int		index;
	float	mid;
	int		len;

	index = -1;
	mid = 0;
	while (++index < size)
		mid += stack->b[index];
	mid = mid / (float)(size);
	index = -1;
	len = 0;
	while (++index < size)
		if (stack->b[0] >= mid)
		{
			ft_pa(stack, 1);
			len++;
		}
		else
			ft_rb(stack, 1);
	index = -1;
	if ((size - len) < stack->size_b)
		while (++index < (size - len))
			ft_rrb(stack, 1);
	return (len);
}

static void	ft_sort2_body(t_stack *stack, int size, int *map)
{
	int	index;
	int	muve;

	index = size;
	while (--index >= 0)
	{
		if (map[index] > 3)
		{
			muve = ft_resort(stack, map[index]);
			map[index] = map[index] - muve;
			if (muve > 3)
			{
				map[index + 1] = muve;
				index = -1;
				while (++index < muve)
					ft_pb(stack, 1);
			}
			else
				ft_sort_a(stack);
			index = size - 1;
		}
		while ((map[index]--) > 0)
			ft_pa(stack, 1);
		ft_sort_a(stack);
	}
}

int			sort2(t_stack *stack)
{
	int	*map;
	int	index;
	int	size;

	size = stack->size_a;
	map = (int *)malloc(sizeof(int) * size);
	index = -1;
	while (stack->size_a > 0)
		map[++index] = ft_to_b(stack, stack->size_a);
	while (++index < size)
		map[index] = 0;
	ft_sort2_body(stack, size, map);
	ft_clearstr_stack(stack);
	free(map);
	return (0);
}
