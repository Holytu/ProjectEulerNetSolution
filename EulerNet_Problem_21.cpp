#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int sum , a , b;
    bool flag = false;
    double answer = 0;	
	
    for (int k = 3 ; k < 10000 ; k++) // k == 220 => a == 284 => b == 220
    {
        flag = false; sum = 0 ; a = 0 ; b = 0 ; 

        for (int i = 2; i <= sqrt(k); i++)
        {
            if(k % i == 0 )
            {
                flag = true;
                sum = sum + i + k/i;
            }
        }    
        if(flag)
            a = sum + 1;

        flag = false; sum = 0; 

        for (int i = 2; i <= sqrt(a); i++)
        {
            if(a % i == 0)
            {
                flag = true;
                sum = sum + i + a / i;
            }
        }
        if(flag)
            b = sum + 1;

        if(k == b && a != b )
        {
            	answer = answer + k;
		//cout<<"k = "<< k << ", a = " << a << endl;
        }

    }
    

   cout << answer << endl;
}
