#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*add)(int, int);
    int result;
    char *error;

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if(handle == NULL)
    {
        error = dlerror();
        printf("Error loading library: %s\n", error);
        return 0;
    }

    add = (int (*)(int, int))dlsym(handle, "add");
    error = dlerror();
    if(error != NULL)
    {
        printf("Error: %s\n", error);
    }
    else
    {
        result = add(5, 3);
        printf("Addition result: %d\n", result);
    }

    add = (int (*)(int, int))dlsym(handle, "addition");
    error = dlerror();
    if(error != NULL)
    {
        printf("Error for invalid function: %s\n", error);
    }
    else
    {
        result = add(5, 3);
        printf("Addition result: %d\n", result);
    }

    dlclose(handle);
    return 0;
}
