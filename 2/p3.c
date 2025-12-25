#include <stdio.h>
#include <dirent.h>

int main()
{
    struct dirent *d;
    DIR *dir = opendir("Dir");

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        if(d->d_name[0] != '.')
            printf("%s\n", d->d_name);
    }

    return 0;
}