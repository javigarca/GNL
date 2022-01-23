/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:50:14 by javigarc          #+#    #+#             */
/*   Updated: 2022/01/12 19:24:56 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

char	*get_next_line(int fd);
char	*get_next_line_2(char **ldr, int endb);
char	*ft_strdup(char *src);
int		ft_strlen(const char *s);
int		ft_searchend(char *str, int c);
char	*ft_feedline(char *str, int len);
char	*ft_substr(char *s, int start, int len);
char	*ft_stradd(char *dest, char *src);
int		ft_readfile(int fdr, char **ldr);

#endif
