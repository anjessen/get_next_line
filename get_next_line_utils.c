/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjessen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:29:30 by anjessen          #+#    #+#             */
/*   Updated: 2020/01/09 17:40:06 by anjessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);

}

char    *ft_strjoin(char *s1,  char *s2)
{
	char    *str;
	int             i;
	int             j;
	size_t          len;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;

	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;

	}
	str[len - 1] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);

}

int			no_lastline(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;

	}
	return (0);

}