/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:58:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/02 00:58:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_free_stack(t_stack *stack, int clear, char **argv)
{
	int	argc;

	free(stack->a);
	free(stack->b);
	free(stack);
	if (clear)
	{
		argc = -1;
		while (argv[++argc] != NULL)
			free(argv[argc]);
		free(argv);
	}
	return (0);
}
