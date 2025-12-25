#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat s;

    if(stat("Marvellous.txt", &s) < 0)
    {
        perror("Error");
        return 0;
    }

    printf("Size: %ld\n", s.st_size);
    printf("Inode: %ld\n", s.st_ino);
    printf("Permissions: %o\n", s.st_mode & 0777);
    printf("Hard Links: %ld\n", s.st_nlink);
    printf("UID: %d  GID: %d\n", s.st_uid, s.st_gid);

    return 0;
}