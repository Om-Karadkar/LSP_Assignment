#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*add)(int, int);
    int (*sub)(int, int);
    int result;

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    add = (int (*)(int, int))dlsym(handle, "addition");
    if(add == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    sub = (int (*)(int, int))dlsym(handle, "subtraction");
    if(sub == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    result = add(10, 5);
    printf("Addition of 10 and 5: %d\n", result);

    result = sub(10, 5);
    printf("Subtraction of 10 and 5: %d\n", result);

    dlclose(handle);
    return 0;
}
