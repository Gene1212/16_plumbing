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
    int fd1;
    char input[100];
    mkfifo("one", 0666);
    mkfifo("two", 0666);
    fd = open("one", O_WRONLY);
    fd1 = open("two", O_RDONLY);

    printf("Pipe connected\n");
    printf("Type in your input\n");

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        write(fd, input, sizeof(input));

        read(fd1, input, sizeof(input));
        printf("%s\n", input);

        remove("one");
        remove("two");
    }

    return 0;
}