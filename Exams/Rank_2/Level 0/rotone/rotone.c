#include <unistd.h>

void rotone(char *str)
{
	int i = 0;
	char	temp;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (str[i] == 'z')
					temp = 'a';
				else
					temp = (str[i] + 1);
				write(1, &temp, 1);
			}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (str[i] == 'Z')
					temp = 'A';
				else
					temp = (str[i] + 1);
				write(1, &temp, 1);
			}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int	ac, char	**av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
