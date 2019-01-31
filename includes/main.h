/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 21:02:14 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"

# define EXIT(){\
	ft_puts("\x1b[31mError\033[0m");\
	return (0);\
	}

typedef struct	s_stack
{
	int			*a;
	int			size_a;
	int			*b;
	int			size_b;
	int			flag_v;
	int			flag_c;
}				t_stack;

int				ft_stack_push_a(t_stack *stack, int n);
void			ft_stack_push_b(t_stack *stack, int n);
void			ft_print_stack(t_stack *stack, int print);
t_stack			*ft_init_stack(int size, char **strs);
int				ft_start_fun(t_stack *stack, char *str, int print);
int				ft_check_arg(int argc, char **argv);
void			ft_sa(t_stack *stack);
void			ft_sb(t_stack *stack);
void			ft_ss(t_stack *stack);
void			ft_pa(t_stack *stack);
void			ft_pb(t_stack *stack);
void			ft_ra(t_stack *stack);
void			ft_rb(t_stack *stack);
void			ft_rr(t_stack *stack);
void			ft_rra(t_stack *stack);
void			ft_rrb(t_stack *stack);
void			ft_rrr(t_stack *stack);

#endif
