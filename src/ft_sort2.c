/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:27:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 07:38:24 by rrhaenys         ###   ########.fr       */
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

static int ft_cmp(t_stack *stack, int p1, int p2, int p3)
{
	return ((stack->a[p1] < stack->a[p2]) && (stack->a[p2] < stack->a[p3]));
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
	if (ft_cmp(stack, 2, 1, 0))
		ft_sa(stack, 1);
	if (ft_cmp(stack, 2, 0, 1))
		ft_sa(stack, 1);
	if (ft_cmp(stack, 0, 2, 1))
	{
		ft_ra(stack, 1);
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	if (ft_cmp(stack, 1, 2, 0))
	{
		ft_ra(stack, 1);
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	if (ft_cmp(stack, 1, 0, 2))
		ft_sa(stack, 1);
}

static void	ft_resort(t_stack *stack, int size)
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
	{
		if (stack->b[0] >= mid)
		{
			ft_pa(stack, 1);
			len++;
		}
		else
			ft_rb(stack, 1);
	}
	ft_printf("size=%d len=%d res=%d size_b=%d\n", size, len, (size - len), stack->size_b);
	if ((size - len) > stack->size_b)
	{
		index = -1;
		while (++index < (size - len))
		{
			ft_rrb(stack, 1);
		}
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
	while(++index < size)
		map[index] = 0;
	index = -1;
	while (stack->size_a > 0)
		map[++index] = ft_to_b(stack, stack->size_a);
	index = size;
	while (--index >= 0)
	{
		if (map[index] > 3)
		{
			ft_resort(stack, map[index]);
			break ;
		}
		while (map[index] > 0)
		{
			ft_pa(stack, 1);
			map[index]--;
		}
		ft_sort_a(stack);
	}
	index = -1;
	while(++index < size)
		ft_printf("answer %d %d\n", index, map[index]);
	return (0);
}