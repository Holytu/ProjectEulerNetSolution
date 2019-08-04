#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double factor1( double n , double r )
{
    
    vector<double> va;
    vector<double> vb;
    double sum = 1;

    for(double i = n - r + 1; i <= n ; i++) // size : r
    {
        va.push_back(i);
    }

    for(double j = 1; j <= r ; j++) 
    {
        vb.push_back(j);
    }

    for (int i = 0 ; i < r ; i++ )
    {
        sum = sum * va[i] / vb[i];
    }
    //cout << "sum = " << sum << endl;

    return sum;
}
double factor2(double n , double r)
{
    double ans = 1;

    for (int i = 1 ; i <= r ; i++ )
    {
        ans = ans * ( n - i + 1 ) / i ;
    }

    return ans;
}
int main()
{
    ///*
    double ans; 
    double number = 0;

    for (double n = 1; n <= 100 ; n++ )
    {
        for (double r = 1; r <= n ; r++ )
        {
            ans = 0;

            if ( n > r )
            {
                ans = factor1(n, r);
            }

            if( ans > pow(10, 6) )
            {
                number++;
                //cout << ans << endl;
            }
        }
    }
    //*/
    cout << "number = " << number << endl;
    return 0;

}