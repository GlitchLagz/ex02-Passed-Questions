#include <unistd.h>

void ctos(char *s)
{
	int i = 0;
	while(s[i])
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			write(1, "_", 1);
			s[i] += 32;
		}
		else
			write(1, &s[i++], 1);
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		ctos(argv[1]);
	write(1, "\n", 1);
	return (0);
}
