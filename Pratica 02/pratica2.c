#include <stdio.h>
#include "estatistica.h"

void main()
{
    printf("%f \n", cauchyDistribution(-2));
    printf("%f \n", gumbelDistribution(0, 0.5, 2));
    printf("%f \n", laplaceDistribution(-6, -5, 4));
}
