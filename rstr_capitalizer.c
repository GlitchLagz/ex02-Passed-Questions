#include <unistd.h>

void	rstr_cap(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] > 64 && str[i] < 91)
				str[i] += 32;
		if ((str[i] > 96 && str[i] < 123) && (str[i + 1] == '\t'
					|| str[i + 1] == ' '|| str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i++], 1);
	}
}
int	main (int argc, char **argv)
{
	int i;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			rstr_cap(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
