#include <unistd.h>
void rot_13(char	*str)
{
	int	i = 0;
	char	temp;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			temp = ((str[i] - 'a' + 13) % 26) + 'a';
			write(1, &temp, 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			temp = ((str[i] - 'A' + 13) % 26) + 'A';
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
		rot_13(av[1]);
	write(1, "\n", 1);
	return(0);
}
