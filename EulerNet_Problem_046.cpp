 #include <iostream>
#include <cmath>
using namespace std;
bool prime[1000000] = {false};
void PrimeMap()
{
	int x = 5, i ;
	prime[2 - 1] = 1; prime[3 - 1] = 1; 

	while(x < 1000000)
	{
		bool flag = true;

		for ( i = 3; i * i <= x ; i+=2)
		{
			if(x % i == 0)
			{
				flag = false;
				break;
			}
		}

		if(flag == true)
		{
			prime[x - 1] = true;
		}

		/*
		if(x == 31)
		{
			cout <<"33 is prime ? " << prime[x] << endl;
		}
		*/

		x += 2;
	}
	
}
int main()
{
	PrimeMap();

	int odd_composite = 33, i ;

	while(true)
	{
		if(prime[odd_composite - 1] == false)
		{
			bool flag = false;

			for ( i = odd_composite - 2 ; i > 2 ; i-=2 )
			{
				if(prime[i - 1] == true)
				{
					int answer = odd_composite - i ;
					double x = sqrt( answer / 2.0 );

					if(x == ( (int) x) )
					{
						flag = true;
						break;
					}
				}	
			}
			
			if(flag == false)
			{
				cout << "odd_composite = " << odd_composite << endl;
				break;
			}
		}
		odd_composite = odd_composite + 2;
	}
	return 0;
}