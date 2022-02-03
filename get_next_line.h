/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:10:20 by javigarc          #+#    #+#             */
/*   Updated: 2022/02/03 20:37:22 by javigarc         ###   ########.fr       */
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
char	*ft_createline(char *src, int len);
int		ft_strlen(const char *s);
int		ft_searchend(char *str, int c);
char	*ft_feedline(char *str, int len);
char	*ft_substr(char *s, int start, int len);
char	*ft_addbuffer(char *ldr, char *buff);
int		ft_readfile(int fdr, char **ldr);

#endif
