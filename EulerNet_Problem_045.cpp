#include <iostream>
#include <cmath>
using namespace std;
bool isTriangle(unsigned long long n)
{
	double x = ( -1 + sqrt( 1 + 8 * n ) ) / 2.0 ;

	return x == ( (int) x ) ;
}
bool isPentagonal(unsigned long long n)
{
	double x = ( 1 + sqrt( 1 + 24 * n ) ) / 6.0 ;

	return x == ( (int) x ) ;
}
bool isHexagonal(unsigned long long n)
{
	double x = ( 1 + sqrt( 1 + 8 * n ) ) / 4.0 ;

	return x == ( (int) x ) ;
}
int main()
{
	unsigned long long tphNumber = 40756;
	
	while(true)
	{
		if(isTriangle(tphNumber)  && isPentagonal(tphNumber) && isHexagonal(tphNumber) )
		{
			cout << tphNumber << endl;
			break;
		}

		tphNumber++;
	}
	
	return 0;
}