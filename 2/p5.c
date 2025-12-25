#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    struct dirent *d;
    struct stat s;
    char path[200], largest[100] = "";
    long max = 0;

    DIR *dir = opendir("Dir");

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        sprintf(path, "Dir/%s", d->d_name);

        if(stat(path, &s) == 0 && S_ISREG(s.st_mode))
        {
            if(s.st_size > max)
            {
                max = s.st_size;
                strcpy(largest, d->d_name);
            }
        }
    }

    printf("Largest File: %s\nSize: %ld bytes\n", largest, max);
    return 0;
}