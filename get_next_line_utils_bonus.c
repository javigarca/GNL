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

char	*ft_createline(char *src, int len)
{
	int		i;
	char	*dst;

	if ((!src) || (len == 0))
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*aux;
	int		i;
	int		z;

	i = start;
	if (!s)
		return (NULL);
	if ((i >= ft_strlen(s)) || (len == 0))
		return (NULL);
	z = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	aux = (char *) malloc(len + 1);
	if (!aux)
		return (0);
	while (z < len)
	{
		aux[z] = s[i];
		z++;
		i++;
	}
	aux[z] = '\0';
	free(s);
	return (aux);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}
