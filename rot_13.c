#include  <unistd.h>

void	rot_13(char *str)
{
	int i = 0;
	int up;
	int low;
	while (str[i] != '\0')
	{
		up = 64;
		low = 96;
		if((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
		{
			if (str[i] > 64 && str[i] < 91)
			{
				up = str[i] - up;
				if(up <= 13)
					str[i] += 13;
				if(up > 13)
					str[i] -= 13;
			}
			if (str[i] > 96 && str[i] < 123)
			{
				low = str[i] - low;
				if(low <= 13)
					str[i] += 13;
				if(low > 13)
					str[i] -= 13;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
}
int	main (int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
