#include <unistd.h>

int	was_printed (char *str, char c, int pos)
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

void	unionn(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i])
	{
		if (!was_printed(s1, s1[i], i))
		write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		int	j = 0;
		int	f = 0;
		while (s1[j])
		{
			if (s1[j] == s2[i])
			{
				f = 1;
				break;
			}
			j++;
		}
		if (!f && !was_printed(s2, s2[i], i))
			write(1, &s2[i], 1);
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 3)
	unionn(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}
