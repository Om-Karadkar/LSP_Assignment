#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle1, *handle2;
    int (*add1)(int, int);
    int (*add2)(int, int);
    int result;

    printf("Loading with RTLD_LAZY\n");
    handle1 = dlopen("./libmath.so", RTLD_LAZY);
    if(handle1 == NULL)
    {
        printf("Error with RTLD_LAZY: %s\n", dlerror());
        return 0;
    }
    printf("Successfully loaded with RTLD_LAZY\n");

    add1 = (int (*)(int, int))dlsym(handle1, "addition");
    if(add1 != NULL)
    {
        result = add1(10, 5);
        printf("Addition with RTLD_LAZY: %d\n", result);
    }

    printf("\nLoading with RTLD_NOW\n");
    handle2 = dlopen("./libmath.so", RTLD_NOW);
    if(handle2 == NULL)
    {
        printf("Error with RTLD_NOW: %s\n", dlerror());
        dlclose(handle1);
        return 0;
    }
    printf("Successfully loaded with RTLD_NOW\n");

    add2 = (int (*)(int, int))dlsym(handle2, "addition");
    if(add2 != NULL)
    {
        result = add2(10, 5);
        printf("Addition with RTLD_NOW: %d\n", result);
    }

    printf("\nRTLD_LAZY resolves symbols at function call time\n");
    printf("RTLD_NOW resolves symbols immediately at dlopen time\n");

    dlclose(handle1);
    dlclose(handle2);
    return 0;
}
