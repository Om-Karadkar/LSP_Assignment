#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    int fd = open("Marvellous.txt", O_RDONLY);

    if(fd < 0)
    {
        perror("Error");
        return 0;
    }

    int bytes = read(fd, buffer, 20);
    write(1, buffer, bytes);

    return 0;
}