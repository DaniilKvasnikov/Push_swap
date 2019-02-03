/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:42:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 20:50:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_pa(t_stack *stack, int print)
{
	int	index;

	if (print)
		ft_puts("pa");
	if (stack->size_b == 0)
		return ;
	ft_stack_push_a(stack, stack->b[0]);
	stack->size_b--;
	index = -1;
	while (++index < stack->size_b)
		stack->b[index] = stack->b[index + 1];
}

void	ft_pb(t_stack *stack, int print)
{
	int	index;

	if (print)
		ft_puts("pb");
	if (stack->size_a == 0)
		return ;
	ft_stack_push_b(stack, stack->a[0]);
	stack->size_a--;
	index = -1;
	while (++index < stack->size_a)
		stack->a[index] = stack->a[index + 1];
}
