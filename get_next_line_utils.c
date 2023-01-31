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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
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

char	*ft_strljoin(char *s1, char *s2, int len)
{
	char	*result;
	int		i_1;
	int		i_2;

	i_1 = 0;
	i_2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i_1] != '\0')
	{
		result[i_1] = s1[i_1];
		i_1++;
	}
	while (s2[i_2] != '\0' || i_2 != len)
	{
		result[i_1++] = s2[i_2++];
	}
	// free(s1);
	return (result);
}
