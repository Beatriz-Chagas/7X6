#include <unistd.h>
#include <stdlib.h>

//void *malloc(size_t size);
//void free(void *ptr);
//void *calloc(size_t nmemb, size_t size);
//void *realloc(void *ptr, size_t size);
int ft_strlen(char *str)
{
	int	i = 0, j = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			j++;
		i++;
	}
	return (i + j);
}
void	camel_to_snake(char *str)
{
	int	i = 0, j = 0;
	char	*size = malloc(ft_strlen(str) + 1);

	if (!size)
		return;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (j != 0)
				size[j++] = '_';
			size[j++] = str[i] + 32;
		}
		else
			size[j++] = str[i];
		i++;
	}
	write(1, size, j);

	size[j] = '\0';
	free(size);
}
int	main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write (1, "\n", 1);
	return (0);
}
