#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    void (*display)(char *);
    char str[100];

    handle = dlopen("./libdisplay.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    display = (void (*)(char *))dlsym(handle, "Display");
    if(display == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if(str[0] != '\0')
    {
        display(str);
    }

    dlclose(handle);
    return 0;
}
