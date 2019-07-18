#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int j = 20;
    int k = 20;
    double numerator = 1;
    double denominator = 1;
    double solution = 0;

    for (int i = (j+k); i>0; i--)
    {
        numerator = numerator * i;
    }
    for (int f = k; f > 0; f--)
    {
        denominator = denominator * f;
    }

    solution = numerator / (denominator * denominator);

    cout << solution ;
	
	return 0;
}
