#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int range = end - start + 1;
	int *res;
	int  i = 0;
	if(end < 0)
		range = (end * -1) - start + 1;
	res = (int *)malloc(sizeof(int) * range);
	if(!res)
		return(NULL);
	while(i <= range)
	{
		if(end < 0)
		{
			while(i <= range)
				res[i++] = start--;
		}
		else
		{
			while(i <= range)
				res[i++] = start++;
		}
	}
	return(res);
}
