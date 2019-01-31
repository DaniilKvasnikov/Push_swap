#include "main.h"

void    ft_print_stack(t_stack *stack, int print)
{
	int index;

	if (!print)
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
