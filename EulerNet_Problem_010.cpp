#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x)
{
	if( x % 2 == 0)
		return false;

	for (int i = 3 ; i <= sqrt(x) ; i+= 2)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int i;
	long long int sum = 2 ;

	for(i = 3; i < 2000000 ; i+=2)
	{
		if(isPrime(i) == true)
		{
			sum = sum + i;
		}
	}
	cout<<sum<<endl;
	return 0;
}
