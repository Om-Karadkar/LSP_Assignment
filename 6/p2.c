#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*add)(int, int);
    int (*sub)(int, int);
    int (*mul)(int, int);
    int (*divide)(int, int);
    int choice;
    int a, b, result;

    handle = dlopen("./libmath2.so", RTLD_NOW);
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

    mul = (int (*)(int, int))dlsym(handle, "multiplication");
    if(mul == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    divide = (int (*)(int, int))dlsym(handle, "division");
    if(divide == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = add(a, b);
            printf("Result: %d\n", result);
            break;
        case 2:
            result = sub(a, b);
            printf("Result: %d\n", result);
            break;
        case 3:
            result = mul(a, b);
            printf("Result: %d\n", result);
            break;
        case 4:
            if(b != 0)
            {
                result = divide(a, b);
                printf("Result: %d\n", result);
            }
            else
            {
                printf("Division by zero not allowed\n");
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    dlclose(handle);
    return 0;
}
