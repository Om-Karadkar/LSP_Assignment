#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    struct dirent *d;
    struct stat s;
    char path[200];
    DIR *dir = opendir("Dir");

    if(dir == NULL)
    {
        perror("Error");
        return 0;
    }

    while((d = readdir(dir)) != NULL)
    {
        if(d->d_name[0] == '.') continue;

        sprintf(path, "Dir/%s", d->d_name);
        lstat(path, &s);

        printf("%s : ", d->d_name);

        if(S_ISREG(s.st_mode)) printf("Regular\n");
        else if(S_ISDIR(s.st_mode)) printf("Directory\n");
        else if(S_ISLNK(s.st_mode)) printf("Link\n");
        else if(S_ISFIFO(s.st_mode)) printf("FIFO\n");
        else if(S_ISCHR(s.st_mode)) printf("Char\n");
        else if(S_ISBLK(s.st_mode)) printf("Block\n");
        else if(S_ISSOCK(s.st_mode)) printf("Socket\n");
    }

    return 0;
}