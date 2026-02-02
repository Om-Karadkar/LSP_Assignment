#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*add)(int, int);
    int (*sub)(int, int);
    int (*mul)(int, int);
    int (*divide)(int, int);
    int (*func_array[4])(int, int);
    int result;
    int i;

    handle = dlopen("./libmath2.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    add = (int (*)(int, int))dlsym(handle, "addition");
    sub = (int (*)(int, int))dlsym(handle, "subtraction");
    mul = (int (*)(int, int))dlsym(handle, "multiplication");
    divide = (int (*)(int, int))dlsym(handle, "division");

    func_array[0] = add;
    func_array[1] = sub;
    func_array[2] = mul;
    func_array[3] = divide;

    printf("Function addresses:\n");
    printf("Addition: %p\n", (void *)func_array[0]);
    printf("Subtraction: %p\n", (void *)func_array[1]);
    printf("Multiplication: %p\n", (void *)func_array[2]);
    printf("Division: %p\n", (void *)func_array[3]);

    printf("\nCalling functions using array:\n");
    result = func_array[0](10, 5);
    printf("Add(10, 5) = %d\n", result);

    result = func_array[1](10, 5);
    printf("Sub(10, 5) = %d\n", result);

    result = func_array[2](10, 5);
    printf("Mul(10, 5) = %d\n", result);

    result = func_array[3](10, 5);
    printf("Div(10, 5) = %d\n", result);

    dlclose(handle);
    return 0;
}
