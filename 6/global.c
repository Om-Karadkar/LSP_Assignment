#include <stdio.h>

int global_value = 0;

void modify_global(int value)
{
    global_value = value;
}

int get_global()
{
    return global_value;
}

void reset_global()
{
    global_value = 0;
}
