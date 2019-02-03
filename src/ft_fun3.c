/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:55:11 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 21:07:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_rra(t_stack *stack, int print)
{
	int	index;
	int	temp;

	if (print)
		stack->str = ft_strjoin(stack->str, "rra\n");
	if (stack->size_a <= 1)
		return ;
	temp = stack->a[stack->size_a - 1];
	index = stack->size_a - 1;
	while (--index >= 0)
		stack->a[index + 1] = stack->a[index];
	stack->a[0] = temp;
}

void	ft_rrb(t_stack *stack, int print)
{
	int	index;
	int	temp;

	if (print)
		stack->str = ft_strjoin(stack->str, "rrb\n");
	if (stack->size_b <= 1)
		return ;
	temp = stack->b[stack->size_b - 1];
	index = stack->size_b - 1;
	while (--index >= 0)
		stack->b[index + 1] = stack->b[index];
	stack->b[0] = temp;
}

void	ft_rrr(t_stack *stack, int print)
{
	if (print)
		stack->str = ft_strjoin(stack->str, "rrr\n");
	ft_rra(stack, 0);
	ft_rrb(stack, 0);
}
