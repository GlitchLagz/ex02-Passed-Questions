#include <unistd.h>

void ptchr(char c)
{
	write(1, &c, 1);
}
void ptnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ptchr('-');
	}
	if (nb >= 10)
	{
		ptnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ptchr(nb + 48);
}
int ftatoi(char *s)
{
	int i = 0;
	int pon = 1;
	int res = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
			|| s[i] == '\n' || s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			pon = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * pon);
}
void tab_mult(char *str)
{
	int nb = ftatoi(str);
	int i = 1;

	while (i < 10)
	{
		ptnbr(i);
		ptchr(' ');
		ptchr('x');
		ptchr(' ');
		ptnbr(nb);
		ptchr(' ');
		ptchr('=');
		ptchr(' ');
		ptnbr(nb * i);
		if (i != 9)
			ptchr('\n');
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
			tab_mult(argv[1]);
	write(1, "\n", 1);
	return (0);
}
