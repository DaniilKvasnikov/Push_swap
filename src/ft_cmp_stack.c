/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 05:14:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 05:14:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_cmp_stack(t_stack *stack, int p1, int p2, int p3)
{
	return ((stack->a[p1] > stack->a[p2]) && (stack->a[p2] > stack->a[p3]));
}
