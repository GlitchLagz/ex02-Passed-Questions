#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *s;
	int i = 0;
	while(src[i])
		i++;
	s = (char *)malloc(sizeof(char) * i + 1);
	if(!s)
		return(NULL);
	i = 0;
	while(src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return(s);
}
