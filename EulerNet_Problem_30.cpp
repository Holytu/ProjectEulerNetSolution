#include <iostream>

using namespace std;
int NumberSum(int x)
{
    int sum = 0, standard = x, digit = 0;
    while(x > 0)
    {
        digit = x % 10;
        digit = digit * digit * digit * digit * digit ;
        x = x / 10;
        sum = sum + digit ;
    }

    return (standard == sum);
}
int main()
{
    //cout << NumberSum(1635) << endl;
    int sum = 0;
    for (int n = 10 ; n < 355000 ; n++)
    {
        if(NumberSum(n) == 1)
        {
            sum = sum + n;
	    cout << " n = " << n << endl;
        }
    } 

    cout << sum << endl ;
    return 0;
}
