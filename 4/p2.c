#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd1, fd2, offset;
    char buffer[100];
    int ret;

    if(argc != 4)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    offset = atoi(argv[3]);

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);

    lseek(fd1, offset, SEEK_SET);

    while((ret = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, ret);
    }

    printf("File copied from offset\n");
    return 0;
}