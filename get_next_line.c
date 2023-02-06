/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/06 15:31:24 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

char	*read_line(int fd, int end_position, char *read_buf, char *result)
{
	int	read_bytes;

	while (end_position == -1)
	{
		read_buf = malloc(sizeof(char) * (BUFFER_SIZE));
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes < BUFFER_SIZE)
			return (read_buf);
		end_position = ft_strchr(read_buf, '\n');
		if (end_position == -1)
		{
			result = ft_strljoin(result, read_buf, BUFFER_SIZE);
			end_position = -1;
		}
		// else if (end_position != -1)
		// {
		// 	result = ft_strljoin(result, read_buf, end_position);
		// 	end_position = ft_strchr(result, '\n');
		// 	end_position = -1;
		// }
		else if (end_position != -1)
		{
			result = ft_strljoin(result, read_buf, end_position);
			end_position = ft_strchr(result, '\n');
			result = ft_substr(
					result, end_position, ft_strlen(result) - end_position);
			end_position = 0;
		}
		ft_free(&read_buf);
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
	result = malloc(sizeof(char) * (BUFFER_SIZE));
	end_position = ft_strchr(read_buf, '\n');
	result = read_line(fd, end_position, read_buf, result);
	ft_free(&read_buf);
	return (result);
}

// char	*get_next_line(int fd)
// {
// 	int			i;
// 	int			len_text;
// 	int			read_bytes;
// 	char		line[BUFFER_SIZE + 1];
// 	char		*result;
// 	static char	*text;

// 	i = 0;
// 	len_text = 0;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	read_bytes = BUFFER_SIZE;
// 	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	read_bytes = read(fd, text, BUFFER_SIZE);
// 	while (!ft_strchr(text, '\n') && read_bytes == BUFFER_SIZE)
// 	{
// 		read_bytes = read(fd, line, BUFFER_SIZE);
// 		line[BUFFER_SIZE] = '\0';
// 		text = ft_strjoin(text, line);
// 	}
// 	while (text[i] != '\0' && text[i] != '\n')
// 		i++;
// 	result = malloc(sizeof(char) * (i + 1));
// 	ft_strlcpy(result, text, i + 1);
// 	while (text[len_text] != '\0')
// 		len_text++;
// 	ft_memmove((void *)text, (void *)text + i + 1, len_text);
// 	return (result);
// }
