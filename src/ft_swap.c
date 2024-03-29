/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:00:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 01:02:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sa(t_stack *stack, int print)
{
	if (print)
		stack->str = ft_strjoin(stack->str, "sa\n");
	if (stack->size_a <= 1)
		return ;
	ft_swap(&(stack->a[0]), &(stack->a[1]));
}

void	ft_sb(t_stack *stack, int print)
{
	if (print)
		stack->str = ft_strjoin(stack->str, "sb\n");
	if (stack->size_b <= 1)
		return ;
	ft_swap(&(stack->b[0]), &(stack->b[1]));
}

void	ft_ss(t_stack *stack, int print)
{
	if (print)
		stack->str = ft_strjoin(stack->str, "ss\n");
	ft_sa(stack, 0);
	ft_sb(stack, 0);
}
