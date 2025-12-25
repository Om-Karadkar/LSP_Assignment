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
    char src[200], dst[200];
    int count = 0;

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        sprintf(src, "SourceDir/%s", d->d_name);
        sprintf(dst, "DestDir/%s", d->d_name);

        if(stat(src, &s) == 0 && S_ISREG(s.st_mode))
        {
            if(rename(src, dst) == 0)
            {
                count++;
            }
        }
    }

    printf("Moved Files: %d\n", count);
    return 0;
}