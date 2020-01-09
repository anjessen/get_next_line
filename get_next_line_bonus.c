/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjessen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:18:22 by anjessen          #+#    #+#             */
/*   Updated: 2020/01/09 17:41:23 by anjessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(int fd, char rest[fd])
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
	if (!(new_rest = malloc(sizeof(char) * ((ft_strlen(rest) - i) + 1))))
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
	static char		*rest[OPEN_MAX];
	int			ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!no_lastline(rest[fd]) && ret != 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buff);
	}
	free(buff);
	*line = get_line(rest[fd]);
	rest[fd] = get_rest(fd, rest[fd]);
	if (ret == 0)
		return (0);
	return (1);
}

/*int main()
  {
  int fd = open("test.txt", O_RDONLY);
  char *line = NULL;
//int fd = -1;
while ((get_next_line(fd, &line)) > 0)
{
printf("================\n");
printf("LINE: %s\n", line);
printf("================\n");
free(line);
}
//printf("LINE: %s\n", line);
//free(line);
//system("leaks a.out");

return 0;
}*/

/*int main()
{
        int fd = open("test.txt", O_RDONLY);
        char *line = NULL;
        while ((get_next_line(fd, &line)) > 0)
        {
                printf("%s\n", line);
        }
        printf("%s\n", line);
        free(line);
        //system("leaks a.out");
        return 0;

}*/
