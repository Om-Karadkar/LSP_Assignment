#include <stdio.h>

int MyStrlen(const char *str)
{
    int length = 0;

    if(str == NULL)
    {
        return 0;
    }

    while(str[length] != '\0')
    {
        length++;
    }

    return length;
}
