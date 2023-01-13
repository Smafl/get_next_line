/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/13 21:43:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*text;
	int		read_size;

	text = malloc(sizeof(char) * 10);
	if (text == NULL)
		return (0);
	read_size = read(fd, text, 9);
	text[10] = '\0';
	printf("fd %d\n read size %d\n", fd, read_size);
	while (*text)
	{
		write(1, text, 1);
		text++;
	}
	return (0);
}
