#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle_str;
    void *handle_math;
    int choice;
    int num, result;
    char str1[100];
    char str2[100];
    char ch;
    int a, b;

    handle_str = dlopen("./libmystring.so", RTLD_LAZY);
    if(handle_str == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 0;
    }

    handle_math = dlopen("./libmymath.so", RTLD_LAZY);
    if(handle_math == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle_str);
        return 0;
    }

    int (*mystrlen)(const char *) = (int (*)(const char *))dlsym(handle_str, "MyStrlen");
    void (*mystrcpy)(char *, const char *) = (void (*)(char *, const char *))dlsym(handle_str, "MyStrcpy");
    void (*mystrcat)(char *, const char *) = (void (*)(char *, const char *))dlsym(handle_str, "MyStrcat");
    int (*mystrcmp)(const char *, const char *) = (int (*)(const char *, const char *))dlsym(handle_str, "MyStrcmp");
    void (*mystrrev)(char *) = (void (*)(char *))dlsym(handle_str, "MyStrrev");
    char *(*mystrchr)(const char *, char) = (char *(*)(const char *, char))dlsym(handle_str, "MyStrchr");

    int (*mysqrt)(int) = (int (*)(int))dlsym(handle_math, "MySqrt");
    int (*myabs)(int) = (int (*)(int))dlsym(handle_math, "MyAbs");
    int (*mymax)(int, int) = (int (*)(int, int))dlsym(handle_math, "MyMax");
    int (*mymin)(int, int) = (int (*)(int, int))dlsym(handle_math, "MyMin");
    int (*myfactorial)(int) = (int (*)(int))dlsym(handle_math, "MyFactorial");
    int (*mygcd)(int, int) = (int (*)(int, int))dlsym(handle_math, "MyGCD");
    int (*mylcm)(int, int) = (int (*)(int, int))dlsym(handle_math, "MyLCM");
    int (*mypower)(int, int) = (int (*)(int, int))dlsym(handle_math, "MyPower");

    while(1)
    {
        printf("\nString Functions Menu:\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Concatenation\n");
        printf("4. String Compare\n");
        printf("5. String Reverse\n");
        printf("6. String Search Character\n");
        printf("\nMath Functions Menu:\n");
        printf("7. Square Root\n");
        printf("8. Absolute Value\n");
        printf("9. Maximum\n");
        printf("10. Minimum\n");
        printf("11. Factorial\n");
        printf("12. GCD\n");
        printf("13. LCM\n");
        printf("14. Power\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                result = mystrlen(str1);
                printf("Length: %d\n", result);
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter destination string: ");
                fgets(str2, sizeof(str2), stdin);
                mystrcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                mystrcat(str1, str2);
                printf("Concatenated: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                result = mystrcmp(str1, str2);
                if(result == 0)
                    printf("Strings are equal\n");
                else if(result > 0)
                    printf("First string is greater\n");
                else
                    printf("Second string is greater\n");
                break;

            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                mystrrev(str1);
                printf("Reversed: %s\n", str1);
                break;

            case 6:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                printf("Enter character to search: ");
                scanf("%c", &ch);
                result = (mystrchr(str1, ch) != NULL);
                if(result)
                    printf("Character found\n");
                else
                    printf("Character not found\n");
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = mysqrt(num);
                printf("Square root: %d\n", result);
                break;

            case 8:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = myabs(num);
                printf("Absolute value: %d\n", result);
                break;

            case 9:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                result = mymax(a, b);
                printf("Maximum: %d\n", result);
                break;

            case 10:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                result = mymin(a, b);
                printf("Minimum: %d\n", result);
                break;

            case 11:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = myfactorial(num);
                printf("Factorial: %d\n", result);
                break;

            case 12:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                result = mygcd(a, b);
                printf("GCD: %d\n", result);
                break;

            case 13:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                result = mylcm(a, b);
                printf("LCM: %d\n", result);
                break;

            case 14:
                printf("Enter base and exponent: ");
                scanf("%d %d", &a, &b);
                result = mypower(a, b);
                printf("Power: %d\n", result);
                break;

            case 15:
                printf("Exiting...\n");
                dlclose(handle_str);
                dlclose(handle_math);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
