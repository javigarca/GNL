/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:47:34 by javigarc          #+#    #+#             */
/*   Updated: 2022/01/12 20:08:47 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stradd(char *dest, char *src)
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
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	if (!src)
	{
		dst = (char *)malloc(sizeof(char) * 1);
		dst[0] = '\0';
		return (dst);
	}
	len = 0;
	while (src[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		exit (1);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;
	size_t	z;

	i = (size_t) start;
	if (!s)
		return (NULL);
	if ((i >= ft_strlen(s)) || (len == 0))
		return (NULL);
	z = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	aux = (char *) malloc(len);
	if (!aux)
		return (0);
	while (z < len)
	{
		aux[z] = s[i];
		z++;
		i++;
	}
	aux[z] = '\0';
	return (aux);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}
