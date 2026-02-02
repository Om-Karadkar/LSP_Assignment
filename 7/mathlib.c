#include <stdio.h>

int MySqrt(int num)
{
    int i = 0;
    int result = 0;

    while(i * i <= num)
    {
        if(i * i == num)
        {
            return i;
        }
        result = i;
        i++;
    }

    return result;
}

int MyAbs(int num)
{
    if(num < 0)
    {
        return -num;
    }
    return num;
}

int MyMax(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int MyMin(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

int MyFactorial(int num)
{
    int result = 1;
    int i;

    if(num < 0)
    {
        return -1;
    }

    for(i = 1; i <= num; i++)
    {
        result = result * i;
    }

    return result;
}

int MyGCD(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MyLCM(int a, int b)
{
    int gcd;
    int lcm;

    gcd = MyGCD(a, b);
    lcm = (a * b) / gcd;

    return lcm;
}

int MyPower(int base, int exp)
{
    int result = 1;
    int i;

    for(i = 0; i < exp; i++)
    {
        result = result * base;
    }

    return result;
}
