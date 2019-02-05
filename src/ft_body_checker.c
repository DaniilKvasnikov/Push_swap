/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:03:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 07:15:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_body_checker(t_stack *stack, int print)
{
	char	*line;
	int		error;

	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if ((error == 1) || (ft_start_fun(stack, line, print) == 0))
			error = 1;
		if (!error)
			ft_print_stack(stack, print, 0);
		free(line);
	}
	return (error);
}
