/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 00:10:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 11:55:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_draw_line(t_data *data, int *p, int size, int color)
{
	int	index;
	int	height;

	if (p[0] < 0 || p[0] >= WIN_W ||
		p[1] < 0 || p[1] >= WIN_H ||
		(p[0] + size - 1) < 0 || (p[0] + size - 1) >= WIN_W)
		return ;
	height = p[1] - 1;
	while (++height < (p[1] + p[2]))
	{
		index = p[0] - 1;
		while (++index < (p[0] + size))
			data->img.data[(height) * WIN_W + index] = color;
	}
}

static double	ft_getmax(t_data *data)
{
	double	max;
	int		index;

	max = 0;
	index = -1;
	while (++index < data->stack->size_a)
		if (abs(data->stack->a[index]) > max)
			max = abs(data->stack->a[index]);
	index = -1;
	while (++index < data->stack->size_b)
		if (abs(data->stack->b[index]) > max)
			max = abs(data->stack->b[index]);
	max = 1 / max * (WIN_H / 2.0);
	return (max);
}

void			ft_draw_stack(t_data *data, int height, double max)
{
	int		pos[3];
	int		index;
	int		color;

	pos[2] = height;
	index = -1;
	index = -1;
	while (++index < data->stack->size_a)
	{
		pos[0] = 0;
		pos[1] = index * height;
		color = 0x00ff00 * (data->stack->a[index] < 0) + 0xff0000;
		ft_draw_line(data, pos, abs(data->stack->a[index]) * max, color);
	}
	index = -1;
	while (++index < data->stack->size_b)
	{
		pos[0] = WIN_H - abs(data->stack->b[index]) * max;
		pos[1] = index * height;
		color = 0x00ff00 * (data->stack->a[index] < 0) + 0x0000ff;
		ft_draw_line(data, pos, abs(data->stack->b[index]) * max, color);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
}

void			ft_print_stack(t_stack *stack, int print, t_data *data)
{
	int index;

	if (data != NULL && data->stack->size_a <= WIN_H)
		ft_draw_stack(data,
		(WIN_H / (data->stack->size_a + data->stack->size_b)), ft_getmax(data));
	if (print != 1)
		return ;
	index = -1;
	ft_printf("a[%d]-> ", stack->size_a);
	while (++index < stack->size_a)
		ft_printf("%d ", stack->a[index]);
	index = -1;
	ft_printf("\nb[%d]-> ", stack->size_b);
	while (++index < stack->size_b)
		ft_printf("%d ", stack->b[index]);
	ft_printf("\n");
}
