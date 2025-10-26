#include <unistd.h>

void alpha_mirror(char *str)
{
	int	i = 0;
	char	temp;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			temp = 'z' - (str[i] - 'a') ;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			temp = 'Z' - (str[i] - 'A') ;
		else
			temp = str[i];
		write(1, &temp, 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write (1, "\n", 1);
	return (0);
}
