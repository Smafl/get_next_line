/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/16 21:05:34 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char *res;
	fd = open("text_2.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	close(fd);
	// system("leaks a.out");
	return (0);
}
