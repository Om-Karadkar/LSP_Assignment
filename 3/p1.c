#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int src, dest, n;
    char buf[100];
    struct stat s;

    src = open("Source.txt", O_RDONLY);
    if(src < 0)
    {
        perror("Error");
        return 0;
    }

    stat("Source.txt", &s);
    dest = open("Destination.txt", O_CREAT | O_WRONLY | O_TRUNC, s.st_mode);

    while((n = read(src, buf, sizeof(buf))) > 0)
    {
        write(dest, buf, n);
    }

    return 0;
}