#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

long total_size = 0;
int file_count = 0;
int dir_count = 0;
char big_file[200];
long big_size = 0;

void scan(char *path)
{
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    char newpath[300];

    dir = opendir(path);
    if(dir == NULL)
        return;

    dir_count++;

    while((dp = readdir(dir)) != NULL)
    {
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        snprintf(newpath, sizeof(newpath), "%s/%s", path, dp->d_name);
        lstat(newpath, &st);

        if(S_ISREG(st.st_mode))
        {
            file_count++;
            total_size += st.st_size;

            if(st.st_size > big_size)
            {
                big_size = st.st_size;
                strcpy(big_file, dp->d_name);
            }
        }
        else if(S_ISDIR(st.st_mode))
        {
            scan(newpath);
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

    scan(argv[1]);

    printf("Files: %d\n", file_count);
    printf("Dirs: %d\n", dir_count);
    printf("Total Size: %ld bytes\n", total_size);
    printf("Largest: %s (%ld bytes)\n", big_file, big_size);

    return 0;
}