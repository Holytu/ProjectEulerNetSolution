#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iterator>
using namespace std;
class PE0060
{
public :
    PE0060() {getPrimeVector(10000);}
    int findLowestSumOfFivePrimes();// => int findLowestSumOfFivePrimes();
    int getPrimeSize();
    bool checkPrimePairs(int prime1 , int prime2 );// => bool checkPrimesPair(int prime1, int prime2);

private :
    vector<int> primes;

    bool isPrime(int n);// => bool checkPrime(int number);
    void getPrimeVector(int maxi);// => void getPrimesVector(int max);
    vector<int> getDigits(int number);// => vector<int> getDigits(int number);

    //vector<int> getConcatenateDigits(int prime1, int prime2);
    
    int getNumberByDigits(vector<int>& digit_vec);
    // => int getNumberByDigits(vector<int>& digits);
    
    //bool ConcatenateDigitsIsPrime(vector<int>& con_digit_num);

    bool ConcatenateDigitsPrime(int prime1 , int prime2);
    // => bool checkConcatenatedPrimes(int prime1, int prime2);
};
int PE0060::getPrimeSize()
{
    return primes.size();
}
bool PE0060::isPrime(int n)
{
    if( n <= 1 || ( n % 2 == 0 && n != 2) )
        return false;

    for (int i = 3 ; i * i <= n ; i+=2 )
    {
        if( n % i == 0)
            return false;
    }
    return true;
}
void PE0060::getPrimeVector(int maxi)
{
    
    for (int m = 3 ; m < maxi ; m+=2 )
    {
        if( isPrime(m) == true)
        {
            primes.push_back(m);
        }
    }
}
vector<int> PE0060::getDigits(int number)
{
    vector<int> digit_vec;

    while(number > 0)
    {
        digit_vec.push_back(number % 10);
        number = number / 10;
    }

    return digit_vec;
}
/*
vector<int> PE0060::getConcatenateDigits(int prime1, int prime2)
{
    vector<int> con_digit_num;

    while( prime2 > 0)
    {
        con_digit_num.push_back( prime2 % 10 );
        prime2 = prime2 / 10;
    }

    while( prime1 > 0)
    {
        con_digit_num.push_back( prime1 % 10 );
        prime1 = prime1 / 10;
    }

    return con_digit_num;
}
*/
int PE0060::getNumberByDigits(vector<int>& digit_vec)
{
    
    int size = digit_vec.size();
    int number = digit_vec[ size - 1 ];

    for (int i = size - 2 ; i >= 0 ; i-- )
    {
        number = 10 * number + digit_vec[i];
    }
    return number;
}
/*
bool PE0060::ConcatenateDigitsIsPrime(vector<int>& con_digit_num)
{
    int a = con_digit_num[0];
    int size_c = con_digit_num.size();
    int size_p = primes.size();

    for (int i = 1; i < size_c ; i++ )
    {
        a = a * 10 + con_digit_num[i];
    }

    for (int i = 0 ; i < size_p ; i++ )
    {
        if( a % primes[i] == 0 )
        {
            return false;
        }
    }

    return true;
}
*/
bool PE0060::ConcatenateDigitsPrime(int prime1 , int prime2)
{
    vector<int> digit_vec1 , digit_vec2;

    digit_vec1 = getDigits(prime1);
    digit_vec2 = getDigits(prime2);

    vector<int>::iterator iter;

    //The root of the code!!!!
    for (iter = digit_vec1.begin() ; iter != digit_vec1.end() ; iter++ )
    {
        digit_vec2.push_back(*iter);
        //Not : digit_vec2.push_back(digit_vec1[*iter]);
    }
    
    int n = getNumberByDigits(digit_vec2);

    return isPrime(n);
}
int PE0060::findLowestSumOfFivePrimes()
{
    int size_p = primes.size();
    int i , j , k , m , n , count  ;

    for ( i = 1 ; i < size_p - 4 ; i++ )
    {
        for ( j = i + 1 ; j < size_p - 3 ; j++ )
        {
            if(checkPrimePairs( primes[i] , primes[j] ) == false)
                continue;
            
            for ( k = j + 1 ; k < size_p - 2 ; k++ )
            {
                if(
                    checkPrimePairs( primes[i] , primes[k] ) == false || 
                    checkPrimePairs( primes[j] , primes[k] ) == false
                  )
                    continue;
                
                for ( m = k + 1 ; m < size_p - 1 ; m++ )
                {
                    if(
                        checkPrimePairs( primes[i] , primes[m] ) == false ||
                        checkPrimePairs( primes[j] , primes[m] ) == false ||
                        checkPrimePairs( primes[k] , primes[m] ) == false
                      )
                        continue;
                    
                    for ( n = m + 1 ; n < size_p ; n++ )
                    {
                        if(
                           checkPrimePairs( primes[i] , primes[n] ) == false || 
                           checkPrimePairs( primes[j] , primes[n] ) == false ||
                           checkPrimePairs( primes[k] , primes[n] ) == false ||
                           checkPrimePairs( primes[m] , primes[n] ) == false
                          )
                        {
                            continue;
                        }
                        
                        return primes[i] +  primes[j] + primes[k] + primes[m] + primes[n];
                
                    }
                }
            }
        }
    }

    return 0;
}
bool PE0060::checkPrimePairs(int prime1 , int prime2 )
{
    if(
        ConcatenateDigitsPrime(prime1 , prime2) == true &&
        ConcatenateDigitsPrime(prime2 , prime1) == true
      )
    {
        return true;
    }
    else
    {
        return false;
    }
    /*
    vector<int> digit_vec1 , digit_vec2 ;
    digit_vec1 = getConcatenateDigits(prime1 , prime2 );
    digit_vec2 = getConcatenateDigits(prime2 , prime1 );

    if(ConcatenateDigitsIsPrime(digit_vec1) == true && ConcatenateDigitsIsPrime(digit_vec2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
}
int main()
{
    PE0060 pe0060;
    //cout << pe0060.getPrimeSize() << endl;
    int lowest_sum = pe0060.findLowestSumOfFivePrimes();
    cout << "lowest_sum = " << lowest_sum << endl;
    return 0;
}