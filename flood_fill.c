typedef struct s_point
{
	int x;
	int y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int j = 0;
	int i;
	char target;
	t_point tmp;
	tmp.x = -1;
	tmp.y = -1;
	while(j < size.y)
	{
		i = 0;
		while(i < size.x)
		{
			if(j == begin.y && i == begin.x)
			{
				target = tab[j][i];
				tab[j][i] = 'F';
				if(j-1 >= 0 && tab[j-1][i] == target)
				{
					tmp.x = i;
					tmp.y = j-1;
					flood_fill(tab, size, tmp);
				}
				if(j+1 < size.y && tab[j+1][i] == target)
				{
					tmp.x = i;
					tmp.y = j+1;
					flood_fill(tab, size, tmp);
				}
				if(i-1 >= 0 && tab[j][i-1] == target)
				{
					tmp.x = i-1;
					tmp.y = j;
					flood_fill(tab, size, tmp);
				}
				if(i+1 < size.x && tab[j][i+1] == target)
				{
					tmp.x = i + 1;
					tmp.y = j;
					flood_fill(tab, size, tmp);
				}
			}
			i++;
		}
		j++;
	}
}
