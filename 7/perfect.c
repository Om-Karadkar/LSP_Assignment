#include "perfect.h"
#include "helper.h"

int IsPerfect(int no)
{
    int sum;

    sum = SumOfFactors(no);

    if(sum == no)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
