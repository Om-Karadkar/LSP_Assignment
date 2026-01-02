#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd, size, i;
    char ch;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        printf("Unable to open file\n");
        return 0;
    }

    size = lseek(fd, 0, SEEK_END);

    for(i = size - 1; i >= 0; i--)
    {
        lseek(fd, i, SEEK_SET);
        read(fd, &ch, 1);
        write(1, &ch, 1);
    }

    return 0;
}