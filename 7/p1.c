#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*is_perfect)(int);
    int number;
    int result;

    handle = dlopen("./libperfect.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    is_perfect = (int (*)(int))dlsym(handle, "IsPerfect");
    if(is_perfect == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 0;
    }

    printf("Enter a number: ");
    scanf("%d", &number);

    result = is_perfect(number);

    if(result == 1)
    {
        printf("%d is a Perfect Number\n", number);
    }
    else
    {
        printf("%d is NOT a Perfect Number\n", number);
    }

    dlclose(handle);
    return 0;
}
