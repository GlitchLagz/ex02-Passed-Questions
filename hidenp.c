#include <unistd.h>

void ptchar(char c)
{
	write(1, &c, 1);
}
void ptnbr(int nb)
{
	if(nb < 0)
	{
		ptchar('-');
		nb = -nb;
	}
	if(nb > 10)
	{
		ptnbr(nb / 10);
		nb %= 10;
	}
	if(nb < 10)
		ptchar(nb + 48);
}
int hide(char *s1, char *s2)
{
	int i = 0;
	int k = 0;
	while(s2[i])
	{
		if(s1[k] == s2[i])
			k++;
		if(s1[k] == '\0')
			return(1);
		i++;
	}
	return(0);
}
int main(int argc, char **argv)
{
	if(argc == 3)
		ptnbr(hide(argv[1], argv[2]));
	write(1, "\n", 1);
	return(0);
}
