#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isPrime(int x)
{
	if ( x <= 1 )
	{
		return false;
	}
	else if ( x == 2 || x == 3)
	{
		return true;
	}
	else if ( ( x & 1 ) == 0 )
	{
		return false;
	}
	else 
	{
		for (int i = 3 ; i * i <= x ; i+=2 )
		{
			if( x % i == 0)
				return false;
		}

		return true;
	}
}
bool isSameDigit(int x, int y)
{
	vector<int> va;
	vector<int> vb;

	while(x > 0 && y > 0)
	{
		va.push_back(x % 10);
		vb.push_back(y % 10);

		x = x / 10;
		y = y / 10;
	}

	sort( va.begin() , va.end() );
	sort( vb.begin() , vb.end() );

	return (va == vb);
}
int main()
{
	vector<int> primes;
	for (int i = 1000; i <= 9999 ; i++)
	{
		if(isPrime(i) == true)
		{
			primes.push_back(i);
		}
	}

	int num = primes.size();

	//cout << num << endl;

	for (int i = 0 ; i <= num - 2 ; i++)
	{
		for (int j = i + 1 ; j < num ; j++)
		{
			int diff = primes[j] -  primes[i];
			int abovePrime = primes[j] + diff;

			if( isPrime(abovePrime) == true)
			{
				bool a = isSameDigit(primes[i] , primes[j]);
				bool b = isSameDigit(primes[j] , abovePrime);
				bool c = isSameDigit(abovePrime, primes[i]);

				if( a && b && c )
				{
					cout << primes[i] << " , " << primes[j] << " , " << abovePrime <<endl;
					break;
				}
			}
		}
	}
	return 0;

}