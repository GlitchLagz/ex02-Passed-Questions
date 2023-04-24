#include <unistd.h>
void ptchar(char c)
{
	write(1, &c, 1);
}
void ptnbr(nb)
{
	if (nb < 0)
	{
		ptchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ptnbr(nb / 10);
		nb %= 10;
	}
	if(nb < 10)
		ptchar(nb + 48);
}
void fizzbuzz(int i)
{
	while(i <= 100)
	{
		if((i % 3 == 0) && (i % 5 == 0))
		{
			write(1, "fizzbuzz", 8);
			write(1, "\n", 1);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz", 4);
			write(1, "\n", 1);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 4);
			write(1, "\n", 1);
		}
		else
		{
			ptnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	int i = 1;
	if(argc == 1)
		fizzbuzz(i);
	return(0);
}
