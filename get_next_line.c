/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjessen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:24:50 by anjessen          #+#    #+#             */
/*   Updated: 2020/01/09 18:47:48 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rest)
		return (0);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (0);
	}
	if (!(new_rest = malloc(sizeof(char) * ((getlen(rest) - i) + 1))))
		return (0);
	i++;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

char	*get_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(new_line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*rest;
	int				ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!no_lastline(rest) && ret != 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free(buff);
	*line = get_line(rest);
	rest = get_rest(rest);
	if (ret == 0)
		return (0);
	return (1);
}
