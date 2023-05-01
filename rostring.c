#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
	int flag;
	if(argc > 1 && argv[1][0])
	{
		while(argv[1][i])
		{
			while(argv[1][i] == ' ' || argv[1][i] == '\t' && argv[1][i])
				i++;
			start = i;
			while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
				i++;
			end = i;
			while(argv[1][i] == ' ' || argv[1][i] == '\t' && argv[1][i])
				i++;
			while(argv[1][i])
			{
				while((argv[1][i] == ' ' && argv[1][i+1] == ' ') || (argv[1][i] == '\t'
							&& argv[1][i+1] == '\t'))
					i++;
				if(argv[1][i] == ' ' || argv[1][i] ==  '\t')
					flag = 1;
				write(1, &argv[1][i++], 1);
			}
		}
		if(flag == 1)
			write(1, " ", 1);
		while(start < end)
			write(1, &argv[1][start++], 1);
	}
	write(1, "\n", 1);
	return(0);
}
