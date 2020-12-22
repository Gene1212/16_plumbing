#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd;
    char input[100];
    mkfifo("one", 0666);

    while (1)
    {
        fd = open("one", O_RDONLY);
        read(fd, input, sizeof(input));
        close(fd);

        char *p = input;
        while (*p)
        {
            (*p += 1);
            p++;
        }

        fd = open("one", O_WRONLY);
        write(fd, input, sizeof(input));
        close(fd);
    }

    return 0;
}