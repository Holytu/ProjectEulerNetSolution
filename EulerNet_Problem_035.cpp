#include <iostream>

using namespace std;
bool prime[1000000] = {false};
int number[7] = {0}; // At most 1,000,000
int head, tail ;

void PrimeMap()
{
    prime[2 - 1] = true; prime[3 - 1] = true; 

    int number = 5;
    bool flag;

    while(number < 1000000)
    {
        int i ;
        flag = true;

        for ( i = 3 ; i * i <= number ; i+=2 )
        {
            if(number % i == 0)
            {

                flag = false;
                break;
            }
        }

        if(flag == true)
        {   
            prime[ number - 1 ] = true;
        }

        number+=2;
    }
}
void IntToArray(int n)
{
    int index = 0; tail = 0;

    // Initial array to zero
    for(int i = 0 ; i < 7 ; i++)
        number[i] = 0;

    // Set number to array. Put one digit in an array position, once a time. 
    while(n > 0)
    {
        number[index] = n % 10;
        n = n / 10;
        index++;
    }

    tail = index - 1;
}
bool Un_RotateIsPrime()
{
    int a = 0 , b = 0, index = 0, computeTime = tail;

    a = number[index];
    index++;

    while(computeTime > 0)
    {
        int dec = index;
        b = number[index];

        while(dec > 0)
        {
            b = b * 10;
            dec--;
        }

        a = a + b;
        index++;
        computeTime--;
    }
    //cout << "Un rotate : " << a << endl;
    return prime[a - 1];
}
bool RotateIsPrime()
{
    int a = 0, b = 0, index = 0, computeTime = tail, rotateTime = tail;
    int correctTime = 0;

    while(rotateTime > 0 )
    {
        //Rotate one bit to left position
        int tmp = number[0] ;
        a = 0 ; b = 0 ; index = 0 ; computeTime = tail ;

        for (int i = 1 ; i <= tail ; i++)
        {
            number[i - 1] = number[i]; 
        }

        number[tail] = tmp;

        a = number[index];
        index++;

        while(computeTime > 0)
        {
            int dec = index;
            b = number[index];

            while(dec > 0)
            {
                b = b * 10;
                dec--;
            }

            a = a + b;
            index++;
            computeTime--;
        }

        if( prime[a - 1] == true )
        {
            correctTime = correctTime + 1;
        }

        rotateTime--;
    }
    return (correctTime == tail);
}
int main()
{
    int t = 0;
    PrimeMap();
    
    for (int n = 2 ; n < 1000000 ; n++)
    {
        IntToArray(n);

        if(Un_RotateIsPrime() && RotateIsPrime() )
        {
            t++;
        }
    }

    cout << t << endl;
    
    return 0;
}