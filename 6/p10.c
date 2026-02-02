#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    printf("RTLD_LAZY vs RTLD_NOW Explanation:\n\n");

    printf("RTLD_LAZY:\n");
    printf("- Symbols are resolved when they are actually used\n");
    printf("- Faster loading of library\n");
    printf("- Missing symbols may not be detected immediately\n");
    printf("- Error occurs at runtime when missing symbol is called\n\n");

    printf("RTLD_NOW:\n");
    printf("- All symbols are resolved at dlopen time\n");
    printf("- Slower loading of library\n");
    printf("- Missing symbols are detected immediately\n");
    printf("- dlopen fails if any symbol is missing\n\n");

    printf("Difference:\n");
    printf("RTLD_LAZY is faster but less safe\n");
    printf("RTLD_NOW is slower but safer and detects errors early\n");

    return 0;
}
