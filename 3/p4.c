#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    DIR *dir = opendir("SourceDir");
    struct dirent *d;
    struct stat s;
    char path[200];
    int count = 0;

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        sprintf(path, "SourceDir/%s", d->d_name);

        if(stat(path, &s) == 0 && S_ISREG(s.st_mode) && s.st_size == 0)
        {
            unlink(path);
            printf("Deleted: %s\n", d->d_name);
            count++;
        }
    }

    printf("Total Deleted: %d\n", count);
    return 0;
}