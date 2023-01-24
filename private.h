/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:56:10 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/24 18:59:26 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

// get_next_line_utils.c
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, int n);

#endif
