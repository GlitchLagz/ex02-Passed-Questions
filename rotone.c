#include <unistd.h>

void	rotone(char *s)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] == 90 || s[i] ==  122)
			s[i] -= 25;
		else if ((s[i] > 64 && s[i] < 90) || (s[i] > 96 && s[i] < 122))
			s[i] += 1;
		write(1, &s[i++], 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
