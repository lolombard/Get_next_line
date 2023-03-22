/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:39 by llombard          #+#    #+#             */
/*   Updated: 2022/11/16 15:59:10 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_freejoin_line(char *str1, char *str2)
{
	char	*newline;

	newline = ft_strjoin(str1, str2);
	free(str1);
	return (newline);
}

static char	*get_new_line(char *strtemp, int fd)
{
	int		i;
	char	*s;

	i = 1;
	s = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!strtemp)
		strtemp = ft_calloc(1, 1);
	while (i > 0)
	{
		if (ft_strchr(strtemp, '\n') != 0)
			break ;
		i = read(fd, s, BUFFER_SIZE);
		if (i < 0)
		{
			free(s);
			return (0);
		}
		s[i] = '\0';
		strtemp = get_freejoin_line(strtemp, s);
	}
	free(s);
	return (strtemp);
}

static char	*get_return_line(char *strtemp)
{
	int		j;
	int		i;
	char	*pt;

	j = 0;
	i = 0;
	if (!strtemp[j])
		return (0);
	while (strtemp[j] != '\n' && strtemp[j] != '\0')
		j++;
	if (strtemp[j] == '\n')
		j++;
	pt = ft_calloc(j + 1, sizeof(char));
	while (i < j)
	{
		pt[i] = strtemp[i];
		i++;
	}
	return (pt);
}

static char	*get_extra_line(char *strex)
{
	int		j;
	int		c;
	char	*pt;

	j = 0;
	c = 0;
	while (strex[j] != '\n' && strex[j] != '\0')
		j++;
	if (strex[j] == '\0')
	{
		free(strex);
		return (0);
	}
	pt = ft_calloc(sizeof(char), (ft_strlen(strex) - j + 1));
	j++;
	while (strex[j] != '\0')
	{
		pt[c] = strex[j];
		c++;
		j++;
	}
	free(strex);
	return (pt);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*strtemp[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	strtemp[fd] = get_new_line(strtemp[fd], fd);
	str = get_return_line(strtemp[fd]);
	strtemp[fd] = get_extra_line(strtemp[fd]);
	return (str);
}
