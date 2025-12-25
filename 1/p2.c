#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("Marvellous.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("Error");
    }
    else
    {
        printf("File opened successfully. FD = %d\n", fd);
    }

    return 0;
}