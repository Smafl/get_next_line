/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/31 19:30:14 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	*ft_memmove(void *dst, const void *src, int n)
{
	int			i;
	char		*pnt_dst;
	const char	*pnt_src;

	pnt_dst = (char *)dst;
	pnt_src = (const char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	if (pnt_dst < pnt_src)
	{
		while (i < n)
		{
			pnt_dst[i] = pnt_src[i];
			i++;
		}
	}
	else if (pnt_dst > pnt_src)
		while (n-- > 0)
			pnt_dst[n] = pnt_src[n];
	return (dst);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		if (len_src < size)
			dst[len_src] = src[len_src];
		len_src++;
	}
	if (size != 0)
	{
		if (len_src < size)
		{
			dst[len_src] = '\0';
		}
		else
		{
			dst[size - 1] = '\0';
		}
	}
	return (len_src);
}

int	ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;
	int		i_1;
	int		i_2;

	len_s1 = 0;
	len_s2 = 0;
	i_1 = 0;
	i_2 = 0;
	while (s1[len_s1++])
		;
	while (s2[len_s2++])
		;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i_1] != '\0')
	{
		result[i_1] = s1[i_1];
		s1++;
	}
	while (s2[i_2] != '\0')
	{
		result[i_1 + i_2] = s2[i_2];
		s2++;
	}
	// free(s1);
	return (result);
}
