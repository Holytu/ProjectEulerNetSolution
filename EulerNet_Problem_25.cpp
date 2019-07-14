#include <iostream>
using namespace std;

int f0[1000] = {0};
int f1[1000] = {0};
int f2[1000] = {0};

int main()
{
    f0[999] = 1; f1[999] = 1;
    int carry = 0, num = 1;

    while(1)
    {
        for (int k = 999 ; k >= 0 ; k--)
        {
            f2[k] = f1[k] + f0[k] + carry;

            if(f2[k] > 10)
            {
                carry = f2[k] / 10;
                f2[k] = f2[k] % 10;
            }
            else
            {
                carry = 0;
            }
            f0[k] = f1[k];
            f1[k] = f2[k];
        }
        num++;
        if(f2[0] > 0)
            break;
    }

    cout<<num;
    return 0;
}
