#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
unsigned long long Pentagonal(unsigned long long n)
{
	return n * ( 3 * n - 1 ) / 2;
}
bool isPentagonal(unsigned long long n)
{
	double penNum = ( 1 + sqrt( 1 + 24 * n) ) / 6.0; 

	return penNum == ( (int) penNum );
}
int main()
{
	for (unsigned long long a = 1 ; a < 3000 ; a++ )
	{
		for (unsigned long long b = a + 1; b < 3000 ; b++ )
		{
			if(isPentagonal( Pentagonal(a) + Pentagonal(b)) && isPentagonal( Pentagonal(b) - Pentagonal(a) ) )
			{
				cout << "a = " << a <<", b = " << b << endl;
				return 0;
			}
		} 
	}
	
	return 0;
}