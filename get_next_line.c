/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:23 by mratke            #+#    #+#             */
/*   Updated: 2024/10/26 19:18:02 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"
#include "unistd.h"

char	*get_next_line(int fd)
{
	char	current_buffer[4];
	size_t	bytes_read;
	char	*final_buffer;

	final_buffer = malloc(sizeof(char));
	final_buffer[0] = '\0';
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (is_in_str(current_buffer, '\n') == 0)
	{
		bytes_read = read(fd, current_buffer, sizeof(current_buffer) - 1);
		current_buffer[bytes_read] = '\0';
		final_buffer = ft_str_merge(final_buffer, current_buffer,
				sizeof(current_buffer) - 1);
	}
	close(fd);
	return (final_buffer);
}
