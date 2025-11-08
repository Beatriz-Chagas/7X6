
int		max(int* tab, unsigned int len)
{
	unsigned int	i = 1;
	int	maxi = tab[0];

	if (len == 0)
		return (0);
	while (tab[i] > maxi)
	{
		tab[i] > maxi;
		i++;
	}
	return (maxi);
}
