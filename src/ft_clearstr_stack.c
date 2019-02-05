/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearstr_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 05:15:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 05:16:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_clearstr_stack(t_stack *stack)
{
	char	*ptr;

	ptr = stack->str;
	while (*ptr != '\0')
	{
		if (ft_strncmp(ptr, "pa\npb\n", 6) == 0)
		{
			ft_strcpy(ptr, (ptr + 6));
			ptr = stack->str;
		}
		else if (ft_strncmp(ptr, "pb\npa\n", 6) == 0)
		{
			ft_strcpy(ptr, (ptr + 6));
			ptr = stack->str;
		}
		else if (ft_strncmp(ptr, "\nrb\nrrb", 7) == 0)
		{
			ft_strcpy(ptr, (ptr + 7));
			ptr = stack->str;
		}
		else
			ptr++;
	}
}
