/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/05 12:04:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"
# include <mlx.h>

# define WIN_W 1300
# define WIN_H 1300
# define WIN_S (WIN_W * WIN_H)

# define EXIT(){ft_puts("\x1b[31mError\033[0m");return (0);}
# define NOARGCH(){ft_puts("\x1b[31m./checker [-v] [0-9]\033[0m");return (0);}
# define NOARGP(){ft_puts("\x1b[31m./push_swap [0-9]\033[0m");return (0);}

typedef struct	s_stack
{
	int			*a;
	int			size_a;
	int			*b;
	int			size_b;
	char		*str;
}				t_stack;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_stack		*stack;
}				t_data;

int				ft_draw(t_data *data);
int				key_release(int key, t_data *data);
int				ft_close(t_data *data);

int				ft_body_checker(t_stack *stack, int print);
int				sort1(t_stack *stack);
int				sort2(t_stack *stack);
int				ft_cmp_stack(t_stack *stack, int p1, int p2, int p3);
void			ft_clearstr_stack(t_stack *stack);
int				ft_free_stack(t_stack *stack, int clear, char **argv);
int				ft_stack_push_a(t_stack *stack, int n);
void			ft_stack_push_b(t_stack *stack, int n);
void			ft_print_stack(t_stack *stack, int print, t_data *data);
t_stack			*ft_init_stack(int size, char **strs);
int				ft_start_fun(t_stack *stack, char *str, int print);
int				ft_check_arg(int argc, char **argv);
void			ft_sa(t_stack *stack, int print);
void			ft_sb(t_stack *stack, int print);
void			ft_ss(t_stack *stack, int print);
void			ft_pa(t_stack *stack, int print);
void			ft_pb(t_stack *stack, int print);
void			ft_ra(t_stack *stack, int print);
void			ft_rb(t_stack *stack, int print);
void			ft_rr(t_stack *stack, int print);
void			ft_rra(t_stack *stack, int print);
void			ft_rrb(t_stack *stack, int print);
void			ft_rrr(t_stack *stack, int print);

#endif
