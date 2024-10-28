/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:23 by mratke            #+#    #+#             */
/*   Updated: 2024/10/28 17:42:53 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*current;
	int		bytes_read;
	char	*final;
	char	*tmp;

	if (fd == -1)
		return (NULL);
	final = malloc(sizeof(char));
	if (final == NULL)
		return (NULL);
	final[0] = '\0';
	current = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (current == NULL)
		return (free(final), NULL);
	current[0] = '\0';
	while (is_in_str(current, '\n') == 0)
	{
		bytes_read = read(fd, current, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(current), free(final), NULL);
		if (bytes_read == 0)
			break ;
		current[bytes_read] = '\0';
		tmp = ft_str_merge(final, current);
		if (tmp == NULL)
			return (free(current), free(final), NULL);
		free(final);
		final = tmp;
	}
	close(fd);
	if (final[0] == '\0')
		return (free(current), free(final), NULL);
	return (free(current), final);
}
