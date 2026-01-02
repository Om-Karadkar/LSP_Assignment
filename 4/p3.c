#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2, i = 0;
    char buffer[100];
    int ret;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);

    while((ret = pread(fd1, buffer, sizeof(buffer), i)) > 0)
    {
        pwrite(fd2, buffer, ret, i);
        i = i + ret;
    }

    printf("File copied using pread and pwrite\n");
    return 0;
}