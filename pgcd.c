#include <stdio.h>
#include <stdlib.h>

void	pgcd(int s1, int s2)
{
	int c = 0;
	int i = 1;
	int tmp = 0;
	if (s2 > s1)
	{
		tmp = s2;
		s2 = s1;
		s1 = tmp;
	}
	while((s1 && s2) && i <= s2)
	{
		if((s1 % i) == 0 && (s2 % i) == 0)
			c = i;
		i++;
	}
	printf("%d", c);
}
int main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
