#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main()
{

    int fd;
    char input[100];
    int x = mkfifo("one", 0666);
    //printf("%s\n", strerror(x));
    printf("Type in your input\n");

    while (1)
    {

        fd = open("one", O_WRONLY);
        fgets(input, sizeof(input), stdin);

        write(fd, input, sizeof(input));
        close(fd);

        fd = open("one", O_RDONLY);
        read(fd, input, sizeof(input));
        printf("%s\n", input);

        close(fd);
    }

    return 0;
}