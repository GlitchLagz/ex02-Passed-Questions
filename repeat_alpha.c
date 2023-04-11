#include <unistd.h>

void	repeat_alpha(char *str)
{	int i = 0;
	int k;
	int j; 

	while (str[i] != '\0')
	{
		j = 0;
		k = 1;
		if (str[i] > 64 && str[i] < 91)
			k = str[i] - 64;
		if (str[i] > 96 && str[i] < 123)
			k = str[i] - 96;
		while (j < k)
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
}
int main (int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
