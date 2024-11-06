
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    // printf("\x1b[2J");      // ekranı temizler
    int fd = open("oku.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));

    // for (;;)
    //     printf("NABER");
}

