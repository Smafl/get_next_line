/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:58 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/11 23:54:02 by ekulichk         ###   ########.fr       */
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
	char	*result;

	fd = open("text_2.txt", O_RDONLY);
	for (int i = 0; i < 18; i++)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
	}
	// result = get_next_line(fd);
	// printf("[%s]", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("[%s]", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	close(fd);
	// system("leaks a.out");
	return (0);
}

/*
cc *.c -LLeakSanitizer -llsan -lc++   -Wno-gnu-include-next -I LeakSanitizer -o push_swap
*/