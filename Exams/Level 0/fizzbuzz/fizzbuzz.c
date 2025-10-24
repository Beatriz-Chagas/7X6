/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:25:05 by bchagas-          #+#    #+#             */
/*   Updated: 2025/10/09 07:11:28 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	*ft_itoa(int n)
{
	static char str[4];
	int i = 0;

	str[0] = '\0';
	str[1] = '\0';
	str[2] = '\0';
	str[3] = '\0';

	if (n > 9)
		str[i++] = (n / 10) + '0';
	str[i++] = (n % 10) + '0';
	str[i] = '\0';
	return (str);
}
int	ft_strlen(char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return (len);
}
void fizzbuzz(int	num)
{
	char	str[4];

	if (num % 15 == 0)
		write(1, "fizzbuzz", 8);
	else if (num % 3 == 0)
		write(1, "fizz", 4);
	else if (num % 5 == 0)
		write(1, "buzz", 4);
	else
	{
		ft_itoa(num);
		write(1, &str, ft_strlen(str));
	}
}
int	main(void)
{
	int	i = 1;
	while (i <= 100)
	{
		fizzbuzz(i);
		write(1, "\n", 1);
		i++;
	}
	return(0);
}
