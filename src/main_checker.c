/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:29:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 11:23:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_is_sort(t_stack *stack)
{
	int	index;

	if (stack->size_b != 0)
	{
		ft_puts("\x1b[31mKO\033[0m");
		return (0);
	}
	index = -1;
	while (++index < (stack->size_a - 1))
		if (stack->a[index] > stack->a[index + 1])
		{
			ft_puts("\x1b[31mKO\033[0m");
			return (0);
		}
	ft_puts("\x1b[32mOK\033[0m");
	return (1);
}

static int	ft_will_print(char *str)
{
	if (!ft_strcmp(str, "-c"))
		return (1);
	if (!ft_strcmp(str, "-v"))
		return (2);
	return (0);
}

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

int			main(int argc, char **argv)
{
	t_stack *stack;
	int		print;
	int		clear;

	if (argc < 2)
		NOARGCH();
	print = ft_will_print(*(++argv));
	argc = argc - 1 - (print > 0);
	argv += (print > 0);
	if (argc < 1)
		NOARGCH();
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = -1;
		while (argv[++argc] != NULL)
			clear = 1;
	}
	if (!ft_check_arg(argc, argv) ||
	((stack = ft_init_stack(argc, argv)) == NULL))
		EXIT();
	ft_print_stack(stack, print, 0);
	if (print == 2)
		ft_open_win("WIN", stack);
	if (!ft_body_checker(stack, print))
		ft_is_sort(stack);
	return (ft_free_stack(stack, clear, argv));
}
