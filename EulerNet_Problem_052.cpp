#include <iostream>
using namespace std;
bool isUnique(int x)
{
	int c[10] = {0};

	while( x > 0)
	{
		c[ (x - 1) % 10]++;

		if(c[ (x - 1) % 10] >= 2)
		{
			return false;
		}
		x = x / 10;
	}

	return true;
}
bool isPerm(int a, int b)
{
	int c[10] = {0};
	bool permutation = true;
	while( a > 0)
	{
		c[ ( a - 1 ) % 10 ]++;

		a = a / 10;
	}

	while( b > 0)
	{
		c[ ( b - 1 ) % 10 ]--;

		b = b / 10;
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		permutation = permutation & !c[i];
	}

	return permutation;
}
int main()
{
	for (int n = 100001 ; n < 1000000 / 6 ; n++ )
	{
		if( isUnique(n) == true)
		{
			bool flag = true;

			for (int i = 1 ; i <= 5 ; i+=2 )
			{
				int a = n * i;
				int b = n * ( i + 1 ) ;
				if( isPerm( a , b ) != true )
				{
					flag = false;
					break;
				}
			}
			if(flag == true)
				cout << "n = " << n << endl;
		}
		
	}
	return 0;
}