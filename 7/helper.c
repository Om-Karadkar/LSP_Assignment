#include "helper.h"

int SumOfFactors(int no)
{
    int sum = 0;
    int i;

    for(i = 1; i < no; i++)
    {
        if(no % i == 0)
        {
            sum = sum + i;
        }
    }
    return sum;
}
