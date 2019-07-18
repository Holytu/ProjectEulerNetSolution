#include <iostream>
#include <math.h>
using namespace std;

int num[9] = {0}; // 0 -> 8 == 1 -> 9
int multiplicand, multiplier, product ;
int sum = 0;
void initialArray()
{
    for (int i = 0 ; i < 9 ; i++)
    {
        num[i] = 0;
    }

    multiplicand = 0;
    multiplier = 0;
    product = 0;
}
void check_multiplicand()
{
    while(multiplicand > 0)
    {
        int x = multiplicand % 10;
        num[x - 1]++;
        multiplicand = multiplicand / 10;
    }
}
void check_multiplier()
{
    while(multiplier > 0)
    {
        int x = multiplier % 10;
        num[x - 1]++;
        multiplier = multiplier / 10;
    }
}
void check_product()
{
    while(product > 0)
    {
        int x = product % 10;
        num[x - 1]++;
        product = product / 10;
    }
}
bool isPandigital()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(num[i] != 1)
            return false;
    }

    return true;
}
void compute(int x)
{
    int flag = 0;

    for (int k = 2; k <= sqrt(x) ; k++)
    {
        if(x % k == 0)
        {
            initialArray();

            multiplicand = k;
            multiplier = x / k;
            product = x;

            check_multiplicand();
            check_multiplier();
            check_product();

            if( isPandigital() == true )
            {
                printf("multiplicand = %d, multiplier = %d, product = %d\n",k, x / k, x);
                sum = sum + x;
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }

}
bool isNotPrime(int x)
{
    if( x == 2)
    {
        return false;
    }
    else if( (x & 1) == 0 && x > 2)
    {
        return true;
    }

    for (int i = 3; i <= sqrt(x) ; i++)
    {
        if(x % i == 0)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    for( int k = 2; k <10000 ; k++)
    {
        if(isNotPrime(k))
        {
            compute(k);
        }
    }

    cout<<sum;
}
