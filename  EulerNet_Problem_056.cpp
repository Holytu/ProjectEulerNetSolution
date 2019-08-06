#include <iostream>
using namespace std;
class p0056
{
private :
    static const int max_digits = 200;
    int m_digitsArray[max_digits];

    void adjustDigitsArray(int m_digitsArray[]);
    int getPowerDigitSums(int a , int b);
public :
    int getMaxDigitSum();
};
void p0056::adjustDigitsArray(int m_digitsArray[])
{
    for (int i = 0 ; i < max_digits - 1 ; i++ )
    {
        m_digitsArray[ i + 1 ] = m_digitsArray[ i + 1 ] + m_digitsArray[ i ] / 10;
        m_digitsArray[ i ] = m_digitsArray[ i ] % 10;
    }
}

int p0056::getPowerDigitSums(int a , int b)
{
    int sum = 0;

    for (int i = 0 ; i < max_digits ; i++ )
    {
        m_digitsArray[i] = 0;
    }

    m_digitsArray[0] = 1;
    
    for (int i = 1; i <= b ; i++)
    {
        for (int j = 0 ; j < max_digits ; j++ )
        {
            m_digitsArray[ j ] = m_digitsArray[ j ] * a;
        }   

        adjustDigitsArray(m_digitsArray);
    }

    for (int i = 0 ; i < max_digits ; i++ )
    {
        sum = sum + m_digitsArray[i];
    }

    return sum;
}
int p0056::getMaxDigitSum()
{
    int sum ;
    int max_a, max_b, max_sum = 0;
    
    for (int a = 2; a < 100 ; a++ )
    {
        for (int b = 2; b < 100 ; b++ )
        {
            sum = getPowerDigitSums(a , b);

            if( sum > max_sum )
            {
                max_sum = sum;
                max_a = a;
                max_b = b;
            }
        }
    }
    cout << "max_a = " << max_a << " , max_b = " << max_b << endl;
    
    return max_sum;
}
int main()
{
    p0056 pe0056;
    
    cout << "The max digit array sum : " << pe0056.getMaxDigitSum() << endl;

}