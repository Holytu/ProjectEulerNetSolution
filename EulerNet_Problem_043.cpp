#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int N = 10;
int prime[7] = {2, 3, 5, 7, 11, 13, 17};
bool isDivided(int n, int index)
{
    int factor = prime[index - 1];

    if( n % factor == 0)
        return true;
    else
        return false;
}
int main()
{
    string digits = "0123456789";
    bool flag;
    unsigned long long x = 0, sum = 0, ssum = 0;
    do
    {
        if(digits[0] != '0')
        {
            flag = true;

            int index;

            for (index = 1; index + 2 < 10; index++)
            {
                string a = digits.substr(index, 3) ;
                x = atoi(a.c_str());

                if(isDivided(x, index) == false)
                {
                    flag = false;
                    break;
                }
            }

            if(flag == true)
            {
                cout << "Digits are : " << digits << endl;
                string a = digits;

                index = 0 ;
                ssum = digits[index] - '0';
                index++;

                while(index < N)
                {
                    ssum = ssum * 10 + (digits[index] - '0');
                    index++;
                }
                sum = sum + ssum;
            }
        }
    }
    while(  next_permutation(  digits.begin(), digits.end() )  );

    cout << "sum = " << sum << endl;

	return 0;
}
