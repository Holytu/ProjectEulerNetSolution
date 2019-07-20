#include <iostream>
#include <math.h>
using namespace std;
long long int FactAns[10] = {0};
long long int Digit[1000] = {};

void InitialDigit() // Initial every digit to be -1
{
    for(int i = 0 ; i < 1000; i++)
    {
        if(Digit[i] != 1)
            Digit[i] = -1;
        else 
            break;
    }
}
void DivideDigit(long long int x) // Set every digit to array
{
    long long int i = 0;

    InitialDigit();

    while(x > 0)
    {
        Digit[i] = x % 10;
        
        x = x / 10;
        i++;
    }
}

void FactorizeMap() // Compute factorize Number from 0 to 9
{
    long long int answer = 1;
    FactAns[0] = 1; FactAns[1] = 1;

    for (int k = 2 ; k < 10 ; k++)
    {
        FactAns[k] = k * FactAns[k-1] ;
    }
}
long long int FactorizeDigit()
{
    long long int answer = 0;
            
    for (int i = 0 ; Digit[i] != -1 ; i++)
    {
        answer = answer + FactAns[ Digit[i] ];
    }
    return answer;
}
int main()
{
    int sum = 0;

    FactorizeMap();
    
    for (int k = 3; k < 1000000 ; k++)
    {
        DivideDigit(k);
        //cout << "k = " << k << ", sum = " << FactorizeDigit() << endl;
        if(FactorizeDigit() == k)
        {
            cout << "k = " << k << ". T/F : " << (FactorizeDigit() == k) <<endl;
            sum = sum + k;
        }
    }

    cout << "sum = " << sum << endl;

    return 0;
}