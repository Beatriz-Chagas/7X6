#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
char    *ft_strdup(char *src)
{
	int	i = 0;
	int	j = 0;
	char *dup = malloc(ft_strlen(src) + 1);

	if (!src)
		return (NULL);
	while (src[i])
		dup[j++] = src[i++];
	dup[j] = '\0';
	return (dup);
}
