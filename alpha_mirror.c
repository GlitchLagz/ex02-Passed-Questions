
#include <unistd.h>

void putchar(char chr)
{
	write(1, &chr, 1);
}
char umirror(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = ('Z' - c + 'A');
	else if (c >= 'a' && c <= 'z')
		c = ('z' - c + 'a');
	return (c);
}
void alpha_mirror(char *str)
{
	int i;
	char new;
	i = 0;
	new = 'a';
	while(str[i] != '\0')
	{
		if(str[i] > 64 && str[i] < 91)
		{
			new = umirror(str[i]);
			putchar(new);
		}
		if(str[i] > 96 && str[i] < 123)
		{
			new = umirror(str[i]);
			putchar(new);
		}
		if(str[i] < 65 || (str[i] > 90 && str[i] < 97) ||
				str[i] > 122)
			putchar(str[i]);
		i++;
	}
}
int main (int argc, char **argv)
{
	if (argc == 2)
	{
		alpha_mirror(argv[1]);
	}
	putchar('\n');
	return  (0);
}
