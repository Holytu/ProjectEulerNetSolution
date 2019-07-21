#include <iostream>
#include <math.h>
using namespace std;
bool prime[1000000] = {false};
int number[10] ;
int tail;

void PrimeList()
{
    int k = 5;
    bool flag;

    prime[2 - 1] = 2 ; prime[3 - 1] = 3; 

    while(k < 1000000)
    {
        flag = true;

        for (int j = 3 ; j <= sqrt(k) ; j+=2 )
        {
            if(k % j == 0)
            {
                flag = false;
                break;
            }
        }

        if(flag == true)
        {
            prime[k - 1] = true;
        }

        k = k + 2;
    }
}
void NumToArray(int n)
{
    int i = 0;
    
    for (int j = 0; j < 10; j++)
    {
        number[j] = 0;
    }

    while(n > 0)
    {
        number[i] = n % 10;
        n = n / 10;
        i++;
    }

    tail = i - 1;
}
bool CheckPrimeFromLeft()
{
    int x , t = 1, index = 0, answer = 0;
    
    answer = number[index] ;
    index++;

    if( prime[answer - 1] == false)
    {
        return false;
    }

    while ( t <= tail )
    {
        int dec = index;
        int sum = number[index];

        while(dec > 0)
        {
            sum = sum * 10;
            dec--;   
        }
        
        answer = answer + sum;

        if( prime[answer - 1] == false)
        {
            return false;
        }

        index++;
        t = t + 1;        
    }
    
    return true;
}
bool CheckPrimeFromRight()
{
    int x , t = tail, index = tail, answer = 0;

    answer = number[index];
    index--;

    if( prime[answer - 1] == false )
        return false;

    while( t > 0 )
    {
        answer = answer * 10 + number[index];

        if( prime[answer - 1] == false)
        {
            return false;
        }

        index--;
        t = t - 1;
    }
    
    return true;
}
int main()
{
    PrimeList(); // Build prime list
    int nth = 0;
    
    
    for (int i = 2 ; i < 1000000 ; i++)
    {
        NumToArray(i);
        if(CheckPrimeFromRight() == true && i > 10 && CheckPrimeFromLeft() == true)
        {
            nth = nth +i;
        }
    }
    
    cout << nth << endl;
    
    return 0;
}