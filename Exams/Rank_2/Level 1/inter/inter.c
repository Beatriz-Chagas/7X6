#include <unistd.h>
int find_printd(char *str, char c, int pos)
{
	int	i = 0;

	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	existed_str(char *str, char c)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void	inter(char *str1, char	*str2)
{
	int	i = 0;

	while (str1[i])
	{
		if (!find_printd(str1, str1[i], i))
		{
			if (existed_str(str2, str1[i]))
				write(1, &str1[i], 1);
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 3)
	inter(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}
