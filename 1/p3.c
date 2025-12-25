#include <stdio.h>
#include <unistd.h>

int main()
{
    if(access("Marvellous.txt", R_OK) == 0)
    {
        printf("Readable\n");
    }
    else
    {
        perror("Not Readable");
    }

    return 0;
}