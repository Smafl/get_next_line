/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/07 21:30:46 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

char	*gnl_get_leftover(int *end_position, char *read_buf)
{
	char	*result;

	return (result);
}

char	*gnl_get_line(int *end_position, char *read_buf)
{
	char	*result;

	return (result);
}

char	*gnl_read_line(int fd, char *read_buf)
{
	int		read_bytes;
	char	*result;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (gnl_strchr(read_buf, '\n') == -1)
	{
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(read_buf);
			free(result);
			return (NULL);
		}
		if (read_bytes < BUFFER_SIZE)
		{
			result = ft_strjoin(result, read_buf);
			gnl_free(&read_buf);
			return (result);
		}
		result = ft_strjoin(result, read_buf);
	}
	free(read_buf);
	return (result);
}

char	*get_next_line(int fd)
{
	int			end_position;
	char		*result;
	static char	*read_buf;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = gnl_read_line(fd, read_buf);
	result = gnl_get_line(&end_position, read_buf);
	read_buf = gnl_get_leftover(&end_position, read_buf);
	return (result);
}

// char	*gnl_read_line(int fd, char *result)
// {
// 	int		end_position;
// 	int		read_bytes;
// 	int		len;
// 	char	*read_buf;

// 	read_buf = NULL;
// 	end_position = gnl_strchr(read_buf, '\n');
// 	while (end_position == -1)
// 	{
// 		read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 2));
// 		read_bytes = read(fd, read_buf, BUFFER_SIZE);
// 		if (read_bytes == 0 || read_bytes == -1)
// 		{
// 			gnl_free(&read_buf);
// 			gnl_free(&result);
// 			return (NULL);
// 		}
		// if (read_bytes < BUFFER_SIZE)
		// {
		// 	// result = gnl_strljoin(result, read_buf, read_bytes);
		// 	result = ft_strjoin(result, read_buf);
		// 	gnl_free(&read_buf);
		// 	return (result);
		// }
// 		end_position = gnl_strchr(read_buf, '\n');
		// if (end_position == -1)
		// {
		// 	// result = gnl_strljoin(result, read_buf, BUFFER_SIZE);
		// 	result = ft_strjoin(result, read_buf);
		// 	end_position = -1;
		// }
		// else if (end_position != -1)
		// {
		// 	// result = gnl_strljoin(result, read_buf, end_position);
		// 	result = ft_strjoin(result, read_buf);
		// 	end_position = gnl_strchr(result, '\n');
		// 	len = gnl_strlen(result);
		// 	// printf("\n\nresult before: [%s]\n", result);
		// 	// printf("end: %d, len: %d, sub: %d\n",
		// 	// 	end_position, len, len - end_position);
		// 	// if (end_position != -1)
		// 	// {
		// 		result = gnl_substr(
		// 				result, end_position, len - end_position);
		// 		// printf("result sub: [%s]\n", result);
		// 	// }
		// 	end_position = 0;
		// }
// 		gnl_free(&read_buf);
// 	}
// 	return (result);
// }

