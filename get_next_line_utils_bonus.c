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

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
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
