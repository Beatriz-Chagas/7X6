/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:29:18 by bchagas-          #+#    #+#             */
/*   Updated: 2025/07/21 20:18:14 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	cont;
	int	i;

	i = 0;
	cont = 0;
	while (tab[i])
	{
		if (f (tab[i++]) == 1)
			cont++;
	}
	return (cont);
}

// #include <stdio.h>
// int verifica_vogal(char *str)
// {
//     int i = 0;
//     while (str[i])
//     {
//         if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
//             str[i] == 'o' || str[i] == 'u')
//             return 1;
//         i++;
//     }
//     return 0;
// }

// int main(void)
// {
//     char *palavras[] = {"batata", "bcdfg", "nuvem", NULL};
//     int count = ft_count_if(palavras, verifica_vogal);

//     printf("Número de strings que contêm vogal: %d\n", count);
//     return 0;
// }
