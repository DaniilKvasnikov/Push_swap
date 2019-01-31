
#include "main.h"

int	ft_start_fun(t_stack *stack, char *str, int print)
{
	if (print)
		ft_printf("\x1b[35m%s\x1b[0m\n", str);
	if (!ft_strcmp(str, "sa"))
		ft_sa(stack);
	else if (!ft_strcmp(str, "sb"))
		ft_sb(stack);
	else if (!ft_strcmp(str, "ss"))
		ft_ss(stack);
	else if (!ft_strcmp(str, "pa"))
		ft_pa(stack);
	else if (!ft_strcmp(str, "pb"))
		ft_pb(stack);
	else if (!ft_strcmp(str, "ra"))
		ft_ra(stack);
	else if (!ft_strcmp(str, "rb"))
		ft_rb(stack);
	else if (!ft_strcmp(str, "rr"))
		ft_rr(stack);
	else if (!ft_strcmp(str, "rra"))
		ft_rra(stack);
	else if (!ft_strcmp(str, "rrb"))
		ft_rrb(stack);
	else if (!ft_strcmp(str, "rrr"))
		ft_rrr(stack);
	else
		EXIT();
	return (1);
}
