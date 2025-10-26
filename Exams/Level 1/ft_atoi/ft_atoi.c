
int	ft_atoi(const char *str)
{
	int i = 1;
	int result = 0;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		i *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 +(*str++ - '0');
	return (i * result);
}
