/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:29:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 21:29:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    ft_print_stack(t_stack *stack)
{
	int index;

	index = -1;
	ft_printf("a-> ");
	while (++index < stack->size_a)
		ft_printf("%d ", stack->a[index]);
	index = -1;
	ft_printf("\nb-> ");
	while (++index < stack->size_b)
		ft_printf("%d ", stack->b[index]);
	ft_printf("\n");
}

int main(int argc, char **argv)
{
	t_stack *stack;

	if (argc > 2)
	{
		if ((stack = ft_init_stack(argc - 1, (argv + 1))) == NULL)
		{
			ft_printf("error\n");
			return (0);
		}
		ft_print_stack(stack);
		ft_sa(stack);
		ft_pb(stack);
		ft_pb(stack);
		ft_pb(stack);
		ft_sa(stack);
		ft_pa(stack);
		ft_pa(stack);
		ft_pa(stack);
		ft_print_stack(stack);
		free(stack->a);
		free(stack->b);
		free(stack);
	}
	return (0);
}
