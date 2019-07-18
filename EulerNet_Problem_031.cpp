#include <iostream>

using namespace std;

int main()
{
    int TwoHundred, OneHundred, Fifty, twenty, ten, five, two, one;
    int cost = 0;
    int time = 0;
    for(TwoHundred = 1; TwoHundred >= 0 ; TwoHundred--)
    {
        for(OneHundred = 2; OneHundred >= 0 ; OneHundred--)
        {
            for(Fifty = 4; Fifty >= 0 ; Fifty--)
            {
                for(twenty = 10; twenty >= 0 ; twenty--)
                {
                    for(ten = 20; ten >= 0 ; ten--)
                    {
                        for(five =40 ; five >= 0 ; five--)
                        {
                            for(two = 100; two >= 0 ; two--)
                            {
                                cost = 0;
                                for(one = 200; one >= 0 ; one--)
                                {
                                    cost = 200 * TwoHundred + 100 * OneHundred + 50 * Fifty + 20 *twenty + 10 *ten + 5 * five + 2 * two + 1 * one;
                                    if(cost == 200)
                                    {
                                        //printf("TwoHundred = %d, OneHundred = %d, Fifty = %d, twenty = %d, ten = %d, five = %d, two = %d, one = %d\n",TwoHundred, OneHundred, Fifty, twenty, ten, five, two, one);
                                        time++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<time;
    return 0;
}
