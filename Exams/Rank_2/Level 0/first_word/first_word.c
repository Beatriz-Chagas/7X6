/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:42:27 by bchagas-          #+#    #+#             */
/*   Updated: 2025/10/06 22:10:11 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	firstword(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] && str[i] != 32 && str[i] != 9)
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		firstword(argv[1]);
	write(1, "\n", 1);
	return (0);
}
