/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:03:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 11:39:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_open_win(char *str, t_stack *stack)
{
	t_data	data;

	if (((data.mlx_ptr = mlx_init()) == 0) ||
		((data.mlx_win =
		mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, str)) == NULL))
		return ;
	data.stack = stack;
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_expose_hook(data.mlx_win, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 1L << 2, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_close, &data);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr,
		&data.img.bpp, &data.img.size_l, &data.img.endian);
	mlx_loop(data.mlx_ptr);
}

int			ft_body_checker(t_stack *stack, int print)
{
	char	*line;
	int		error;

	if (print == 2)
		ft_open_win("WIN", stack);
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
