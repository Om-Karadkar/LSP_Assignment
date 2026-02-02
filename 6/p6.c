#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    void (*modify)(int);
    int (*get)(void);
    void (*reset)(void);
    int value;

    handle = dlopen("./libglobal.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    modify = (void (*)(int))dlsym(handle, "modify_global");
    get = (int (*)(void))dlsym(handle, "get_global");
    reset = (void (*)(void))dlsym(handle, "reset_global");

    printf("Initial value: %d\n", get());

    modify(100);
    printf("After modify(100): %d\n", get());

    modify(50);
    printf("After modify(50): %d\n", get());

    printf("Global variable persists across calls\n");

    reset();
    printf("After reset: %d\n", get());

    dlclose(handle);
    return 0;
}
