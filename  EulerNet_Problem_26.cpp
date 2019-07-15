#include <iostream>
#include <math.h>
using namespace std;
int N = 1000;
int MAXDIGITS = 4096;
int decimal[MAXDIGITS];
int numerator[MAXDIGITS];

int getCycles(int d)
{
    int start, end, i, j, n =1;

    i = 0;
    numerator[i] = n % d;
    decimal[i] = numerator[i] * 10 / d;

    for ( i = 1 ; ; i++)
    {
        numerator[i] = numerator[i-1] * 10 % d;
        decimal[i] = numerator[i] * 10 / d;

        for( j = 0; j < i ; j++)
        {
            if(numerator[j] == numerator[i])
                break;
        }

        if( j < i )
        {
            start = j;
            end = i - 1;
            break;
        }

        if(numerator[i] == 0)
        {
            start = i;
            end = i;
            break;
        }
    }

    return end - start + 1;
}
int main()
{
    int max_d, max = 1, cycles;

    for (int d = 1; d < N ; d++)
    {
        cycles = getCycles(d);
        if(max < cycles)
        {
            max = cycles;
            max_d = d;
        }
    }

    cout << "max = " << max << endl;
    cout << "max_d = " << max_d << endl;
    return 0;
}