#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

double cauchyDistribution(double x)
{
    return 1/( M_PI * ( 1 + pow(x, 2) ) );
}

double gumbelDistribution(double x, double mi, double beta)
{
    double z = (x - mi) / beta;
    return (1/beta) * exp(-(z + exp(-z)));
}

double laplaceDistribution(double x, double mi, double b)
{
    return (1/(2 * b)) * exp(-fabs(x - mi)/(2 * b));
}
void main()
{
    printf("%f \n", cauchyDistribution(-2));
    printf("%f \n", gumbelDistribution(0, 0.5, 2));
    printf("%f \n", laplaceDistribution(-6, -5, 4));
}
