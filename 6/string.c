#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_lowercase(char *str)
{
    int count = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(islower(str[i]))
            count++;
    }
    return count;
}

int count_uppercase(char *str)
{
    int count = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(isupper(str[i]))
            count++;
    }
    return count;
}

int count_digits(char *str)
{
    int count = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(isdigit(str[i]))
            count++;
    }
    return count;
}
