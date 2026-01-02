#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buffer[100];
    int ret;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0)
    {
        printf("Unable to open source file\n");
        return 0;
    }

    fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if(fd2 < 0)
    {
        printf("Unable to create destination file\n");
        return 0;
    }

    while((ret = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, ret);
    }

    printf("File copied successfully\n");
    return 0;
}