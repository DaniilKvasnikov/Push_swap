/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:53:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 20:57:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_ra(t_stack *stack, int print)
{
	int	index;
	int	temp;

	if (print)
		stack->str = ft_strjoin(stack->str, "ra\n");
	if (stack->size_a <= 1)
		return ;
	temp = stack->a[0];
	index = -1;
	while (++index < (stack->size_a - 1))
		stack->a[index] = stack->a[index + 1];
	stack->a[index] = temp;
}

void	ft_rb(t_stack *stack, int print)
{
	int	index;
	int	temp;

	if (print)
		stack->str = ft_strjoin(stack->str, "rb\n");
	if (stack->size_b <= 1)
		return ;
	temp = stack->b[0];
	index = -1;
	while (++index < (stack->size_b - 1))
		stack->b[index] = stack->b[index + 1];
	stack->b[index] = temp;
}

void	ft_rr(t_stack *stack, int print)
{
	if (print)
		stack->str = ft_strjoin(stack->str, "rr\n");
	ft_ra(stack, 0);
	ft_rb(stack, 0);
}
