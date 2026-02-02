#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char *argv[])
{
    void *handle;
    void *symbol;
    char libpath[256];
    char symname[256];

    if(argc != 3)
    {
        printf("Usage: %s <library_path> <symbol_name>\n", argv[0]);
        return 0;
    }

    strcpy(libpath, argv[1]);
    strcpy(symname, argv[2]);

    handle = dlopen(libpath, RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return 0;
    }

    symbol = dlsym(handle, symname);
    if(symbol == NULL)
    {
        printf("Symbol not found: %s\n", dlerror());
    }
    else
    {
        printf("Symbol found: %s\n", symname);
        printf("Address: %p\n", symbol);
    }

    dlclose(handle);
    return 0;
}
