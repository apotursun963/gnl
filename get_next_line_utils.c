
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int	    size;
	int	    index;

	size = ft_strlen(src);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	index = -1;
	while (++index < size)
		str[index] = src[index];
	str[index] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == (char)chr)
			return ((char *)str);
		str++;
	}
	if ((char)chr == '\0')
		return ((char *)str);
	return (NULL);
}

#include <stdio.h>
char	*ft_strjoin(char *result, char *buff)
{
	char	*assemble;
	size_t	index;

    if (!result)
    {
        result = ft_strdup("");
    }
	if (!result || !buff)
		return (NULL);
	assemble = (char *)malloc((ft_strlen(result) + ft_strlen(buff)) + 1);
    if (!assemble)
		return (NULL);
	index = -1;
	while (++index < (ft_strlen(result) + ft_strlen(buff)))
	{
		if (index < ft_strlen(result))
			assemble[index] = result[index];
		else
			assemble[index] = buff[index - ft_strlen(result)];
	}
	assemble[index] = '\0';
    free(result);
	return (assemble);
}
