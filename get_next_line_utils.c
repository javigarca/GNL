/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:47:34 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/25 17:57:50 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_sz;
	size_t	s_sz;

	d_sz = 0;
	s_sz = 0;
	while (dest[d_sz] != 00)
		d_sz++;
	while (src[s_sz] != 00)
		s_sz++;
	i = d_sz;
	j = 0;
	if (size < 1)
		return (s_sz + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < d_sz)
		return (s_sz + size);
	return (d_sz + s_sz);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	char	*string;
	int		totalsize;

	if ((!s1) || (!s2))
		return (NULL);
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	pos = (size_t)totalsize + 1;
	string = (char *)malloc(sizeof(char) * (totalsize) + 1);
	if (!string)
		return (0);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	ft_strlcat(string, s2, pos);
	string[ft_strlen(string)] = 00;
	return ((char *) string);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != 00))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 00;
		return (1);
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		exit (1);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
