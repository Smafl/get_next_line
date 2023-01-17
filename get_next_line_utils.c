/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/01/17 18:03:58 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlcpy(char *dst, const char *src, int size)
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

char	*ft_strchr(const char *s, int c)
{
	while ((char)*s != (char)c)
	{
		if ((char)*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1++])
		;
	while (s2[len_s2++])
		;
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == NULL)
		return (NULL);
	len_s1 = -1;
	len_s2 = -1;
	while (s1[++len_s1])
		result[len_s1] = s1[len_s1];
	while (s2[++len_s2])
		result[len_s2 + len_s1] = s2[len_s2];
	result[len_s2 + len_s1] = '\0';
	free(s1);
	return (result);
}
