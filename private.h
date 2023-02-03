/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:56:10 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/03 15:41:18 by ekulichk         ###   ########.fr       */
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
#  define BUFFER_SIZE 35
# endif

// get_next_line_utils.c
void	ft_free(char **str);
int		ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strljoin(char *s1, char *s2, int len);
void	*ft_memmove(void *dst, const void *src, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
