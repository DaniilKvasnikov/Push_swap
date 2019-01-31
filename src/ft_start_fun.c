
#include "main.h"

int	ft_start_fun(t_stack *stack, char *str, int print)
{
	if (print)
		ft_printf("\x1b[35m%s\x1b[0m\n", str);
	if (ft_strcmp(str, "sa") == 0)
		ft_sa(stack);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb(stack);
	else if (ft_strcmp(str, "ss") == 0)
		ft_ss(stack);
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa(stack);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb(stack);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra(stack);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb(stack);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(stack);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra(stack);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb(stack);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rrr(stack);
	else
		EXIT();
	return (1);
}
