#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    void *handle;
    int (*add)(int, int);
    int result;
    char libpath[256];

    printf("Load without LD_LIBRARY_PATH set\n");
    printf("Trying to load libmath.so\n");
    handle = dlopen("libmath.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        printf("Library not found in default search paths\n\n");
    }
    else
    {
        add = (int (*)(int, int))dlsym(handle, "addition");
        result = add(10, 5);
        printf("Addition: %d\n", result);
        dlclose(handle);
    }

    printf("Load with full path\n");
    handle = dlopen("./libmath.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
    }
    else
    {
        printf("Successfully loaded with full path\n");
        add = (int (*)(int, int))dlsym(handle, "addition");
        result = add(20, 15);
        printf("Addition: %d\n", result);
        dlclose(handle);
    }

    printf("\nWhen LD_LIBRARY_PATH is set, library can be found\n");
    printf("Without it, only standard paths and full paths work\n");

    return 0;
}
