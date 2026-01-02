#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    char path[300];

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    dir = opendir(argv[1]);
    if(dir == NULL)
    {
        printf("Cannot open directory\n");
        return 0;
    }

    while((dp = readdir(dir)) != NULL)
    {
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s", argv[1], dp->d_name);
        lstat(path, &st);

        printf("%s  ", dp->d_name);

        if(S_ISREG(st.st_mode)) printf("FILE ");
        else if(S_ISDIR(st.st_mode)) printf("DIR  ");
        else if(S_ISLNK(st.st_mode)) printf("LINK ");
        else printf("OTHER ");

        printf("%ld ", st.st_size);

        printf((st.st_mode & S_IRUSR) ? "r" : "-");
        printf((st.st_mode & S_IWUSR) ? "w" : "-");
        printf((st.st_mode & S_IXUSR) ? "x" : "-");
        printf((st.st_mode & S_IRGRP) ? "r" : "-");
        printf((st.st_mode & S_IWGRP) ? "w" : "-");
        printf((st.st_mode & S_IXGRP) ? "x" : "-");
        printf((st.st_mode & S_IROTH) ? "r" : "-");
        printf((st.st_mode & S_IWOTH) ? "w" : "-");
        printf((st.st_mode & S_IXOTH) ? "x" : "-");

        printf("  %s", ctime(&st.st_mtime));
    }

    return 0;
}