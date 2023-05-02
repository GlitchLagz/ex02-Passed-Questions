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
	if(nb >= 10)
	{
		ptnbr(nb / 10);
		nb %= 10;
	}
	if(nb < 10)
		ptchar(nb + 48);
}
int	ft_atoi(char *s)
{
	int i = 0;
	int pon = 1;
	int res = 0;
	while(s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
			|| s[i] == '\r' || s[i] == '\n' || s[i] == '\f')
		i++;
	if(s[i] == '-' || s[i] == '+')
	{
		if(s[i] == '-')
			pon = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return(res * pon);
}
int aps(int nb)
{
	int res = 0;
	int i = 3;
	while(i <= nb)
	{
		if(i == nb)
		{
			res += i;
			return(res + 2);
		}
		if(nb % i != 0)
			res += i;
		i += 2;
	}
	return(res);
}
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		ptnbr(aps(ft_atoi(argv[1])));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, "\n", 1);
	}
	return(0);
}
