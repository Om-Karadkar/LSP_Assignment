#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char str[] = "Hello from Marvellous\n";
    int fd = open("Marvellous.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("Error");
        return 0;
    }

    int bytes = write(fd, str, strlen(str));
    printf("Bytes Written: %d\n", bytes);

    return 0;
}