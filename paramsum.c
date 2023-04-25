#include <unistd.h>
int atoi(char *s)
{
	int i =0;
	int pon = 1;
	int res = 0;

	while(s[i] == ' ' || s[i] == '\n' || s[i] == '\f'
			|| s[i] == '\t' || s[i] == '\v' || s[i] == '\r')
		i++;
	if(s[i] == '-' || s[i] == '+')
	{
		if(s[i] == '-')
			pon = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return(pon * res);
}
void ptchar(char c)
{
	write(1, &c, 1);
}
void ptnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if(nb > 10)
	{
		ptnbr(nb / 10);
		nb = nb % 10;
	}
	if(nb < 10)
	{
		ptchar(nb + 48);
	}
}
int main(int argc, char **argv)
{
	if(argc > 1)
	{
		int i = 0;
		while(argv[i])
			i++;
		ptnbr(i - 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, "\n", 1);
	}
}
