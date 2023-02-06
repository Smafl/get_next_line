/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:56:10 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/06 21:06:57 by ekulichk         ###   ########.fr       */
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
#  define BUFFER_SIZE 2
# endif

// get_next_line_utils.c
void	gnl_free(char **str);
int		gnl_strlen(const char *str);
int		gnl_strchr(const char *s, int c);
char	*gnl_strljoin(char *s1, char *s2, int len);
char	*gnl_substr(const char *s, unsigned int start, int len);

#endif
