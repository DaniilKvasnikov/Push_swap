
#include "main.h"

int	ft_check_arg(int argc, char **argv)
{
	int		index;
	char	*c;

	index = -1;
	if (argc == 0)
		return (0);
	while (++index < argc)
	{
		c = argv[index];
		if (*c == '-')
		{
			c++;
			if (*c == '\0')
			return (0);
		}
		while (*c != '\0')
		{
			if (*c < '0' || *c > '9')
				return (0);
			c++;
		}
	}
	return (1);
}
