#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void show(char *path, int level)
{
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    char newpath[300];
    int i;

    dir = opendir(path);
    if(dir == NULL)
        return;

    while((dp = readdir(dir)) != NULL)
    {
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        for(i = 0; i < level; i++)
            printf("  ");

        snprintf(newpath, sizeof(newpath), "%s/%s", path, dp->d_name);
        lstat(newpath, &st);

        if(S_ISDIR(st.st_mode))
        {
            printf("[D] %s\n", dp->d_name);
            show(newpath, level + 1);
        }
        else if(S_ISREG(st.st_mode))
        {
            printf("[F] %s\n", dp->d_name);
        }
        else if(S_ISLNK(st.st_mode))
        {
            printf("[L] %s\n", dp->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    printf("%s\n", argv[1]);
    show(argv[1], 1);

    return 0;
}