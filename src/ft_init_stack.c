/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:06:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 21:09:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_stack_push_a(t_stack *stack, int n)
{
	int index;

	index = stack->size_a;
	while (--index >= 0)
		stack->a[index + 1] = stack->a[index];
	stack->a[0] = n;
	stack->size_a++;
}

void	ft_stack_push_b(t_stack *stack, int n)
{
	int index;

	index = stack->size_b;
	while (--index >= 0)
		stack->b[index + 1] = stack->b[index];
	stack->b[0] = n;
	stack->size_b++;
}

t_stack	*ft_malloc_stack(int size)
{
	t_stack *stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((stack->a = (int *)malloc(sizeof(int) * size)) == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->size_a = 0;
	if ((stack->b = (int *)malloc(sizeof(int) * size)) == NULL)
	{
		free(stack);
		free(stack->a);
		return (NULL);
	}
	stack->size_b = 0;
	return (stack);
}

t_stack	*ft_init_stack(int size, char **strs)
{
	t_stack	*stack;
	int		index;

	if ((stack = ft_malloc_stack(size)) == NULL)
		return (NULL);
	index = size;
	while (--index >= 0)
	{
		ft_stack_push_a(stack, ft_atoi(strs[index]));
	}
	return (stack);
}
