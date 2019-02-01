/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:10:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 01:18:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_fun(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa(stack);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb(stack);
	else if (ft_strcmp(str, "ss") == 0)
		ft_ss(stack);
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa(stack);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb(stack);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra(stack);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb(stack);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(stack);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra(stack);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb(stack);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rrr(stack);
	else
		return (0);
	return (1);
}

int			ft_start_fun(t_stack *stack, char *str, int print)
{
	if (print)
		ft_printf("\x1b[35m%s\x1b[0m\n", str);
	if (ft_fun(stack, str) == 0)
		EXIT();
	return (1);
}
