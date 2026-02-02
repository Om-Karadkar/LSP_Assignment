#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main()
{
    void *handle;
    int (*count_lower)(char *);
    int (*count_upper)(char *);
    int (*count_digit)(char *);
    char str[100];
    int choice;

    handle = dlopen("./libstring.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    count_lower = (int (*)(char *))dlsym(handle, "count_lowercase");
    count_upper = (int (*)(char *))dlsym(handle, "count_uppercase");
    count_digit = (int (*)(char *))dlsym(handle, "count_digits");

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    printf("1. Count lowercase\n");
    printf("2. Count uppercase\n");
    printf("3. Count digits\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Lowercase letters: %d\n", count_lower(str));
            break;
        case 2:
            printf("Uppercase letters: %d\n", count_upper(str));
            break;
        case 3:
            printf("Digits: %d\n", count_digit(str));
            break;
        default:
            printf("Invalid choice\n");
    }

    dlclose(handle);
    return 0;
}
