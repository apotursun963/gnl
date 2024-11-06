


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


#include <stdlib.h>
#include <unistd.h>

char    *read_all_line(int fd, char *result);
char    *get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *result, char *buff);
char	*ft_strchr(const char *str, int chr);


typedef struct  s_lst
{
    char            *buff;
    struct s_lst    *next;
}   t_lst;









#endif