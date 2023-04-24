#include <stdlib.h>

int arrlen(int nb)
{
	int len = 0;
	if(nb <= 10)
		len++;
	while(nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
char *ft_itoa(int nbr)
{
	char *res;
	int len = arrlen(nbr);
	res = (char *)malloc(sizeof(char) * len + 1);
	if(!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return(res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while(nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return(res);
}
