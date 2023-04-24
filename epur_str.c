#include <unistd.h>
int ftlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}
void	epur(char *s)
{
	int len = ftlen(s);
	int i = 0;
	int c = 0;
	while(s[i] == ' ' || s[i] == '\t')
	{
		i++;
		c++;
	}
	while(i < len)
	{
		while((s[i] == ' ' || s[i] == '\t') && (s[i] != '\0'))
			i++;
		if((s[i-1] == ' '|| s[i-1] == '\t') && ((i - c) != 0) && (s[i] != '\0'))
			write(1, " ", 1);
		write(1, &s[i], 1);
		i++;
		if(s[i+1] == '\0' && (s[i] == ' ' || s[i] == '\t'))
			return;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		epur(argv[1]);
	write(1, "\n", 1);
	return(0);
}
