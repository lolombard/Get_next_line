/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:48 by llombard          #+#    #+#             */
/*   Updated: 2022/11/16 15:50:12 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*news;
	int		i;
	int		line1;

	i = 0;
	line1 = ft_strlen(str1);
	news = (char *)malloc(sizeof(char) * (line1 + ft_strlen(str2) + 1));
	if (!str1 || !str2 || !news)
		return (NULL);
	while (str1[i] != '\0')
	{
		news[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		news[line1 + i] = str2[i];
		i++;
	}
	news[line1 + i] = '\0';
	return (news);
}

void	ft_bzero(void *str, size_t n)
{
	size_t				i;
	unsigned char		*pt;

	i = 0;
	pt = (unsigned char *)str;
	while (i < n)
	{
		pt[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}
