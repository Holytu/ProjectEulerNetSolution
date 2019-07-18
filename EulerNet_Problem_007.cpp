#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int x)
{
	if( x % 2 == 0)
		return false;

	for(int i = 3; i <= sqrt(x) ; i+=2 )
	{
		if(x % i == 0)
			return false;
	}

	return true;
}
int main()
{
	int nth = 1 ;
	long long int number = 2;
	while(nth < 10001)
	{
		if(isPrime(number) == true)
			nth++;
		
		number++;
	}
	number-- ;
	cout<<number;
	return 0;
}
