#include <stdio.h>

void Display(char *str)
{
    int count = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    printf("String: %s\n", str);
    printf("Total characters: %d\n", count);
}
