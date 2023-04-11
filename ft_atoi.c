int	ft_atoi(char *arr)
{
	int i = 0;
	int pon = 1;
	int res = 0;
	while (arr[i] == '\n' || arr[i] == '\t' || arr[i] == '\r'
			|| arr[i] == '\f' || arr[i] == ' ' || arr[i] == '\v')
		i++;
	if (arr[i] == '-' || arr[i] == '+')
	{
		if (arr[i] == '-')
			pon = -1;
		i++;
	}
	while ((arr[i] >= '0') && (arr[i] <= '9'))
	{
		res = (res * 10) + (arr[i] - '0');
		i++;
	}
	return (res * pon);
}
