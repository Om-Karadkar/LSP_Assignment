#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *dir = opendir("SourceDir");
    struct dirent *d;

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        if(strcmp(d->d_name, "Source.txt") == 0)
        {
            printf("Found: SourceDir/%s\n", d->d_name);
            return 0;
        }
    }

    printf("File not found\n");
    return 0;
}