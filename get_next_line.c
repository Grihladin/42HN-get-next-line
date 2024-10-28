/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:23 by mratke            #+#    #+#             */
/*   Updated: 2024/10/28 21:07:17 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *current_line)
{
	char	*tmp;
	char	*chars_readed;
	int		bytes_readed;

	chars_readed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (chars_readed == NULL)
		return (free(current_line), NULL);
	chars_readed[0] = '\0';
	while (is_in_str(chars_readed, '\n') == 0)
	{
		bytes_readed = read(fd, chars_readed, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(chars_readed), free(current_line), NULL);
		if (bytes_readed == 0)
			break ;
		chars_readed[bytes_readed] = '\0';
		tmp = ft_str_merge(current_line, chars_readed);
		if (tmp == NULL)
			return (free(chars_readed), free(current_line), NULL);
		free(current_line);
		current_line = tmp;
	}
	free(chars_readed);
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
