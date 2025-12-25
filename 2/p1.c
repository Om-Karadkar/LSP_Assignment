#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[100];
    int fd = open("Marvellous.txt", O_RDONLY), bytes, total = 0;

    if(fd < 0)
    {
        perror("Error");
        return 0;
    }

    while((bytes = read(fd, buf, sizeof(buf))) > 0)
    {
        write(1, buf, bytes);
        total += bytes;
    }

    printf("\nTotal Bytes: %d\n", total);
    return 0;
}