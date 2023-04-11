#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int pon = 1;
	int res = 0;

	while (s[i] == '\n' || s[i] == '\v' || s[i] == '\t'
			|| s[i] == '\r' || s[i] == ' ' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			pon = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - 48);
		i++;
	}
	return (pon * res);
}

void	ptchar(char c)
{
	write(1, &c, 1);
}

void	ptnbr(int nb)
{
	if(nb < 0)
	{
		ptchar('-');
		nb = -nb;
	}
	if(nb > 100)
	{
		ptchar('1');
		ptchar('0');
	}
	if(nb > 10)
	{
		ptnbr(nb / 10);
		nb = nb % 10;
	}
	if(nb < 10)
		ptchar(nb + 48);
}

void	tab_mult(char *str)
{
	int i = 1;
	int nb = ft_atoi(str);
	while(i < 10)
	{
		ptnbr(i);
		ptchar(' ');
		ptchar('x');
		ptchar(' ');
		ptnbr(nb);
		ptchar(' ');
		ptchar('=');
		ptchar(' ');
		ptnbr(i * nb);
		ptchar('\n');
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return(0);
}
