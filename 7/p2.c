#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle_add;
    void *handle_sub;
    int (*add)(int, int);
    int (*sub)(int, int);
    int a, b;
    int result_add;
    int result_sub;

    handle_add = dlopen("./libaddition.so", RTLD_LAZY);
    if(handle_add == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    handle_sub = dlopen("./libsubstraction.so", RTLD_LAZY);
    if(handle_sub == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle_add);
        return 0;
    }

    add = (int (*)(int, int))dlsym(handle_add, "Addition");
    if(add == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle_add);
        dlclose(handle_sub);
        return 0;
    }

    sub = (int (*)(int, int))dlsym(handle_sub, "Substraction");
    if(sub == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle_add);
        dlclose(handle_sub);
        return 0;
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    result_add = add(a, b);
    result_sub = sub(a, b);

    printf("Addition: %d + %d = %d\n", a, b, result_add);
    printf("Substraction: %d - %d = %d\n", a, b, result_sub);

    dlclose(handle_add);
    dlclose(handle_sub);
    return 0;
}
