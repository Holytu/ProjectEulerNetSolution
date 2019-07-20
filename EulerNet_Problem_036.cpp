#include <iostream>
using namespace std;

int Decimal_Palindromes_Number[10] = {};
int Binary_Palindroms_Number[20] = {};

bool Binary_palindromes(int n)
{
    int k = 0;

    for (int i = 0 ; i < 20 ; i++)
    {
        Binary_Palindroms_Number[i] = 0;
    }

    while(n > 0)
    {
        if(n & 1)
        {
            Binary_Palindroms_Number[k] = 1;
        }
        else
        {
            Binary_Palindroms_Number[k] = 0;
        }
        k++;
        n = n / 2;
    }

    for (int i = 0 , j = k - 1; i < j ; i++, j--)
    {
        if( Binary_Palindroms_Number[i] != Binary_Palindroms_Number[j])
        {
            return false;   
        }
    }

    return true;
}
bool decimal_palindromes(int n)
{
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        Decimal_Palindromes_Number[i] = 0;
    }

    while(n > 0)
    {
        Decimal_Palindromes_Number[k] = n % 10;
        n = n / 10;
        k++;
    }
    
    for (int i = 0, j = k - 1 ; i < j ; i++ , j--)
    {
        if(Decimal_Palindromes_Number[i] != Decimal_Palindromes_Number[j])
            return false;
    }

    return true;
}
int main()
{
    int sum = 0;
    for (int x = 18; x < 1000000 ; x++)
    {
        if(decimal_palindromes(x) && Binary_palindromes(x))
        {
            //cout << x << endl;
            sum = sum + x;
        }
    }
    cout << sum << endl;
    return 0;
}