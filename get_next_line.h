/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:31 by mratke            #+#    #+#             */
/*   Updated: 2024/10/26 19:17:54 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// includes
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Utils
int		is_in_str(char *s, char c);
char	*ft_str_merge(char *s1, char *s2, int buffer_size);
char	*get_next_line(int fd);

#endif
