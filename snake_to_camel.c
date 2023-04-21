#include <unistd.h>

void	stoc(char *s)
{
	int i = 0;
	int flag = 0;
	while(s[i])
	{
		if(s[i] == '_')
		{
			i++;
			flag = 1;
		}
		if ((s[i] >= 'a' && s[i] <= 'z') || (
					s[i] >= 'A' && s[i] <= 'Z'))
		{
			if (flag == 1 && (s[i] >= 'a' && s[i] <= 'z'))
			{
				s[i] -= 32;
				flag = 0;
			}
		}
		write(1, &s[i++], 1);
	}
}
int main (int argc, char **argv)
{
	if (argc == 2)
		stoc(argv[1]);
	write( 1,"\n", 1);
	return (0);
}
