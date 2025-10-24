/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:24:42 by bchagas-          #+#    #+#             */
/*   Updated: 2025/09/14 19:09:28 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_text(int fd, char *text)
{
	int		get_bytes;
	char	*buffer;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!text)
		text = ft_strdup("");
	get_bytes = 1;
	while (text && !ft_strchr(text, '\n') && get_bytes > 0)
	{
		get_bytes = read(fd, buffer, BUFFER_SIZE);
		if (get_bytes <= 0)
			break ;
		buffer[get_bytes] = '\0';
		tmp = text;
		text = ft_strjoin(text, buffer);
		free(tmp);
	}
	free(buffer);
	if (get_bytes == -1 || !text || text[0] == '\0')
		return (free(text), NULL);
	return (text);
}

char	*ft_get_line(char *text)
{
	char	*line;
	int		i;
	int		j;

	if (!text || text[0] == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = text[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_text(char *text)
{
	char	*new_text;
	int		i;
	int		j;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	i++;
	if (text[i] == '\n')
	i++;
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	new_text = malloc(ft_strlen(text + i) + 1);
	if (!new_text)
		return (NULL);
	j = 0;
	while (text[i])
		new_text[j++] = text[i++];
	new_text[j] = '\0';
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*rest_text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_text = ft_read_text(fd, rest_text);
	if (!rest_text)
		return (NULL);
	line = ft_get_line(rest_text);
	if (!line)
		return (NULL);
	rest_text = ft_trim_text(rest_text);
	return (line);
}
