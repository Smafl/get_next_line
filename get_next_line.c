/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/17 18:05:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			len_text;
	int			read_bytes;
	char		*line;
	char		*result;
	static char	*text = NULL;

	i = 0;
	len_text = 0;
	read_bytes = BUFFER_SIZE;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (text == NULL)
	{
		text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_bytes = read(fd, text, BUFFER_SIZE);
		text[BUFFER_SIZE] = '\0';
	}
	while (!ft_strchr(text, '\n') && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		line[BUFFER_SIZE] = '\0';
		text = ft_strjoin(text, line);
	}
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	ft_strlcpy(result, text, i + 1);
	while (text[len_text] != '\0')
		len_text++;
	ft_memmove((void *)text, (void *)text + i + 1, len_text);
	if (text == NULL || text[i] == '\0')
		return (NULL);
	free(line);
	return (result);
}
