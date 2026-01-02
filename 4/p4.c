#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int out, in, i, r;
    char buffer[100];

    if(argc < 3)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    out = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);

    for(i = 2; i < argc; i++)
    {
        in = open(argv[i], O_RDONLY);

        while((r = read(in, buffer, sizeof(buffer))) > 0)
        {
            write(out, buffer, r);
        }

        close(in);
    }

    printf("Files merged successfully\n");
    return 0;
}