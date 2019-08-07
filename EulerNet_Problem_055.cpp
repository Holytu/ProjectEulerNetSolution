#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class PE0055
{
public:
    bool checkPalindromeNumber(int number, int iteration);
    int getNumOfLynchrelNumbers(int max);

private:
    vector<int> getDigits(int number);
    vector<int> reverseAndAddDigits(vector<int>& num_digits_vec);
    bool checkLynchrelNumber(int number, int max_iterations);
    bool checkPalindrome(vector<int> digit_vec);
};
bool PE0055::checkPalindromeNumber(int number, int iteration) //v
{
    vector<int> num_digits_vec;
    vector<int> sum_digits_vec;
    
    num_digits_vec = getDigits(number);


    while(iteration > 0)
    {
        
        sum_digits_vec = reverseAndAddDigits(num_digits_vec);
        
        if( checkPalindrome(sum_digits_vec) == true )
        {
            return true;
        }
        
        num_digits_vec = sum_digits_vec;

        iteration = iteration - 1;
    }

    return false;
}
int PE0055::getNumOfLynchrelNumbers(int max) //v
{
    int numberOfLynchrel = 0;

    for (int number = 1 ; number < max ; number++ )
    {
        if(checkLynchrelNumber(number , 50 ) == true)
        {
            numberOfLynchrel = numberOfLynchrel + 1;
        }
    }

    return numberOfLynchrel;
}
vector<int> PE0055::getDigits(int number) //v
{
    vector<int> num_digits_vec;

    while(number > 0)
    {
        num_digits_vec.push_back(number % 10);
        number = number / 10;
    }

    return num_digits_vec;
}
vector<int> PE0055::reverseAndAddDigits(vector<int>& num_digits_vec) // ?
{
    int size = num_digits_vec.size();
    int c_in = 0;
    
    vector<int> reverse_num_digits_vec;
    vector<int> sum_digits_vec(size);
    
    for (int i = num_digits_vec.size() - 1 ; i >= 0 ; i-- )
    {
        reverse_num_digits_vec.push_back(num_digits_vec[i]);
    }
    
    
    for (int i = 0 ; i < size ; i++ )
    {
        sum_digits_vec[i] += num_digits_vec[i] + reverse_num_digits_vec[i] ;//
        c_in = sum_digits_vec[i] / 10;
        sum_digits_vec[i] = sum_digits_vec[i] % 10;

        if( i + 1 < size )
        {
            sum_digits_vec[i + 1] = sum_digits_vec[i + 1] + c_in;
        }
    }

    if( c_in > 0 )
    {
        sum_digits_vec.push_back( 1/*c_in / 10 */) ;
    }

    return sum_digits_vec;
}
bool PE0055::checkLynchrelNumber(int number, int max_iterations) //v
{
    vector<int> num_digits_vec;
    vector<int> sum_digits_vec;

    num_digits_vec = getDigits(number);
        
    for(int n = 1 ; n <= max_iterations ; n++ )
    {
        sum_digits_vec = reverseAndAddDigits(num_digits_vec);

        if( checkPalindrome(sum_digits_vec) == true )
        {
            return false;///??
        }

        num_digits_vec = sum_digits_vec;
    }

    return true;///??
}
bool PE0055::checkPalindrome(vector<int> digit_vec) //v
{
    int i , j;
    for ( i = 0 , j = digit_vec.size() - 1 ; i <= j ; i++ , j-- )
    {
        if(digit_vec[i] != digit_vec[j])
        {
            return false;
        }
    }

    return true;
}
int main()
{
    PE0055 pe0055;

    assert(true == pe0055.checkPalindromeNumber(349, 3));

    cout << pe0055.getNumOfLynchrelNumbers(10000) << endl;

    return 0;
}