#include <unistd.h>

void rprint(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	i--;
	while(i >= 0)
		write(1, &s[i--], 1);
}
int main(int argc, char **argv)
{
	if(argc == 2)
		rprint(argv[1]);
	write(1, "\n", 1);
	return(0);
}
