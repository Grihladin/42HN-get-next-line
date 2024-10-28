/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:23 by mratke            #+#    #+#             */
/*   Updated: 2024/10/28 21:01:09 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *current_line)
{
	char	*tmp;
	char	*readed_chars;
	int		readed_bytes;

	readed_chars = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (readed_chars == NULL)
		return (free(current_line), NULL);
	readed_chars[0] = '\0';
	while (is_in_str(readed_chars, '\n') == 0)
	{
		readed_bytes = read(fd, readed_chars, BUFFER_SIZE);
		if (readed_bytes == -1)
			return (free(readed_chars), free(current_line), NULL);
		if (readed_bytes == 0)
			break ;
		readed_chars[readed_bytes] = '\0';
		tmp = ft_str_merge(current_line, readed_chars);
		if (tmp == NULL)
			return (free(readed_chars), free(current_line), NULL);
		free(current_line);
		current_line = tmp;
	}
	free(readed_chars);
	return (current_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	buffer = read_line(fd, buffer);
	if (buffer == NULL || buffer[0] == '\0')
		return (free(buffer), NULL);
	return (buffer);
}
