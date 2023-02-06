/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/06 21:14:05 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	gnl_free(char **str)
{
	free(*str);
	*str = NULL;
}

int	gnl_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	gnl_strchr(const char *s, int c)
{
	int	end_position;

	end_position = 0;
	if (s == NULL)
		return (-1);
	while (s && s[end_position])
	{
		if (s[end_position] == c)
			return (end_position);
		end_position++;
	}
	return (-1);
}

char	*gnl_strljoin(char *s1, char *s2, int len)
{
	char	*result;
	int		i_1;
	int		i_2;

	i_1 = 0;
	i_2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (gnl_strlen(s1) + len + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i_1] != '\0')
	{
		result[i_1] = s1[i_1];
		i_1++;
	}
	while (s2[i_2] != '\0' && i_2 != len)
	{
		result[i_1++] = s2[i_2++];
	}
	result[i_1] = '\0';
	gnl_free(&s1);
	return (result);
}

char	*gnl_substr(const char *s, unsigned int start, int len)
{
	char	*result;
	int		i;
	int		len_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = gnl_strlen(s);
	if (len_s - start < len)
		len = len_s - start;
	result = malloc(sizeof(char) * (len * (len_s >= start) + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	if (len_s < start)
		return (result);
	while (i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
