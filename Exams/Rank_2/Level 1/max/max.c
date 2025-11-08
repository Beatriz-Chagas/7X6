int		max(int* tab, unsigned int len)
{
	int i = 0;
	int maxnum = 0;

	if (len == 0 || tab == NULL)
		return (0);
	while (i < len)
	{
		if (tab[i] > maxnum)
			maxnum = tab[i];
		i++;
	}
	return (maxnum);
}

// #include <stdio.h>

// int main (void)
// {
// 	int int_tab[] = {1, 6, 8, 24, 2, 3};
// 	printf("%d \n", max(int_tab, 6));
// 	return (0);
// }