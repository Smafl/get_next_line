/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/06 23:00:38 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

char	*gnl_read_line(int fd, int end_position, char *read_buf, char *result)
{
	int	read_bytes;
	int	len;

	result = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	while (end_position == -1)
	{
		read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 2));
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes == 0 || read_bytes == -1)
		{
			gnl_free(&read_buf);
			return (NULL);
		}
		if (read_bytes < BUFFER_SIZE)
		{
			result = gnl_strljoin(result, read_buf, read_bytes);
			gnl_free(&read_buf);
			return (result);
		}
		end_position = gnl_strchr(read_buf, '\n');
		if (end_position == -1)
		{
			result = gnl_strljoin(result, read_buf, BUFFER_SIZE);
			end_position = -1;
		}
		else if (end_position != -1)
		{
			result = gnl_strljoin(result, read_buf, end_position);
			end_position = gnl_strchr(result, '\n');
			len = gnl_strlen(result);
			if (end_position != -1)
				result = gnl_substr(
						result, end_position + 1, len - end_position);
			end_position = 0;
		}
		gnl_free(&read_buf);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	int			end_position;
	char		*read_buf;
	static char	*result;

	read_buf = NULL;
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	end_position = gnl_strchr(read_buf, '\n');
	result = gnl_read_line(fd, end_position, read_buf, result);
	gnl_free(&read_buf);
	return (result);
}
