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
    int fd1;
    char input[100];
    mkfifo("one", 0666);
    mkfifo("two", 0666);

    fd = open("one", O_RDONLY);
    fd1 = open("two", O_WRONLY);

    while (1)
    {
        read(fd, input, sizeof(input));

        char *p = input;
        while (*p)
        {
            (*p += 1);
            p++;
        }

        write(fd1, input, sizeof(input));
    }

    return 0;
}