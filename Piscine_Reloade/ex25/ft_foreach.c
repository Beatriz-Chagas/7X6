/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:50:58 by bchagas-          #+#    #+#             */
/*   Updated: 2025/07/21 20:16:25 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_putnbr(int nb)
// {
// 	long int	i;

// 	i = nb;
// 	if (i < 0)
// 	{
// 		ft_putchar('-');
// 		i = -i;
// 	}
// 	if (i < 10)
// 		ft_putchar(i + '0');
// 	else
// 	{
// 		ft_putnbr (i / 10);
// 		ft_putchar (i % 10 + '0');
// 	}
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	cont;

	cont = 0;
	while (cont < length)
		f(tab[cont++]);
}
// int	main(void)
// {
// 	int tab[4]= {1,5,6,2};
// 	ft_foreach(tab, 4, &ft_putnbr);
// 	return(0);
// }
