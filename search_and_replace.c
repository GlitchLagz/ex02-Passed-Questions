#include <unistd.h>
int ftlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
void snr(char *str, char *s, char *r)
{
	int i = 0;
	if((ftlen(s) + ftlen(r)) != 2)
		return ;
	while (str[i])
	{
		if(str[i] == s[0])
			str[i] = r[0];
		write(1, &str[i++], 1);
	}
}
int main(int argc, char **argv)
{
	if (argc == 4)
		snr(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}
