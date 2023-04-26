#include <unistd.h>

void fword(char *s)
{
	int  i = 0;
	while((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	while(!(s[i] == ' ' || s[i] == '\t') && s[i])
		write(1, &s[i++], 1);
}
int main(int argc, char **argv)
{
	if(argc == 2)
		fword(argv[1]);
	write(1, "\n", 1);
	return(0);
}
