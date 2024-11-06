// ilk olarak bütün dosyayı oku ve tampon bölgeye yerleştir
// daha sonra bu tampon bölgeden tek bir satır oku ve bunu döndür
// en sonunda bir sonraki satıra geç

#include "get_next_line.h"
#include <stdio.h>


// char    *read_all_line(int fd, char *result)
// {
//     char    *buff;
//     int     bytes;

//     buff = (char *)malloc(BUFFER_SIZE + 1);
//     if (!buff)
//         return (NULL);
//     bytes = 1;
//     while (bytes > 0 && BUFFER_SIZE >= 0)
//     {
//         bytes = read(fd, buff, BUFFER_SIZE);
//         if (bytes < 0)
//         {
//             free(buff);
//             return (NULL);
//         }
//         buff[bytes] = '\0';
//         result = ft_strjoin(result, buff);
//         if (!result)
//             return (NULL);
//     }
//     free(buff);
//     return (result);
// }


// char    *get_next_line(int fd)
// {
//     static char    *buffer = NULL;
//     // char    *one_line;

//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);

//     buffer = read_all_line(fd, buffer);

//     return (buffer);
// }

// -Okuma: Dosyadan BUFFER_SIZE kadar veri okunur.
// -Bağlantılı Listeye Ekleme: Okunan veriler bağlantılı listeye düğüm olarak eklenir.
// -Satır Sonu Kontrolü: Eğer satır sonu (\n) bulunursa okuma işlemi sonlanır.
// -Birleştirme ve Döndürme: Bağlantılı listeyi birleştirip, tek bir string haline getiririz ve sonucu döndürürüz.
// -Bellek Temizleme: Her okunan satır sonrasında bağlantılı listeyi serbest bırakırız.

// dosyadan BUFFER_SIZE kadar veri okur ve '\0' sonunda ekler 
// ve düğüm olarak listeye eklenir. ve bu işlem satır sonuna kadar devam edilir
// satır sonuna gelindiğinde ise listedeki bütün düğümler birleştirilir ve return ettirilir.
// okunan(return) satır tamamlandıktan sonra liste free lenir

void    write_lst(void);    // linked list kontrol/test et

char    *merge_nodes(t_lst  **lst)
{
    t_lst   *current_unit;
    int     totla_len;
    char    *merge;
    int     i;
    int     j;

    totla_len = 0;
    current_unit = *lst;
    while (current_unit)            // ft_strlen'i yeninden yapılandır
    {
        totla_len += ft_strlen(current_unit->buff);
        current_unit = current_unit->next;
    }
    merge = malloc(totla_len  +1);
    if (!merge)
        return (NULL);
    i = 0;
    current_unit = *lst;
    while (current_unit)
    {
        j = 0;
        while (current_unit->buff[j] != '\0')
            merge[i++] = current_unit->buff[j++];
        current_unit = current_unit->next;
    }
    merge[i] = '\0';
    merge[i++] = '\n';
    return (merge);
}

char    *convert_str(char *content)
{
    char    *str;

    int len = ft_strlen(content);
    str = malloc(len +1);
    if (!str)
        return (NULL);

    int i = 0;
    while (i < len)
    {
        if (content[i] == '\n')
            break ;
        else
            str[i] = content[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void    append_lst(t_lst **lst, t_lst *unit)
{
    t_lst   *current_unit;

    if (!*lst)
    {
        *lst = unit;
        return ;
    }
    current_unit = *lst;
    while (current_unit->next != NULL)
        current_unit = current_unit->next;
    current_unit->next = unit;
}

t_lst   *create_node(char *content)
{
    t_lst   *new_unit;

    new_unit = malloc(sizeof(t_lst));
    if (!new_unit)
        return (NULL);
    new_unit->buff = convert_str(content);
    new_unit->next = NULL;
    return (new_unit);
}

char    *read_one_line(int fd, char *result, t_lst **lst)
{
    char    buff[BUFFER_SIZE +1];
    int     bytes;
    t_lst   *unit;

    bytes = read(fd, buff, BUFFER_SIZE);
    buff[bytes] = '\0';

    unit = create_node(buff);
    append_lst(lst, unit);

    if (buff[bytes++] != '\n')
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        buff[bytes] = '\0';
        unit = create_node(buff);
        append_lst(lst, unit);
    }
    result = merge_nodes(lst);
    free(lst);
    return (result);
}   

char    *get_next_line(int fd)
{
    t_lst   *lst = NULL;
    char    *one_line = NULL;

    one_line = read_one_line(fd, one_line, &lst);
    return (one_line);
}
