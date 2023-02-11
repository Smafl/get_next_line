/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:15:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/12 00:14:05 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

// get_next_line.c
char	*get_next_line(int fd);
void	gnl_free(char **ptr);

// get_next_line_utils.c
int		gnl_strlen(const char *str);
int		gnl_strchr(const char *s, int c);
void	*gnl_memcpy(void *dst, const void *src, int n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char *s2);

#endif
