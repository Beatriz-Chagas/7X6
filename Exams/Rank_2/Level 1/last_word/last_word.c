#include <unistd.h>

void	last_word(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	i--;
	while ((str[i] == 32) || (str[i] == 9))
		i--;
	while ((str[i] != 32) && (str[i] != 9))
		i--;
	i++;
	while (str[i] && (str[i] != 32) && (str[i] != 9))
		write(1, &str[i++], 1);
}
int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write (1, "\n", 1);
	return (0);
}
