#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*mystrlen)(const char *);
    char str[100];
    int length;

    handle = dlopen("./libmystring.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    mystrlen = (int (*)(const char *))dlsym(handle, "MyStrlen");
    if(mystrlen == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if(str[0] != '\0')
    {
        length = mystrlen(str);
        printf("String length: %d\n", length);
    }
    else
    {
        printf("String is NULL or empty\n");
    }

    dlclose(handle);
    return 0;
}
