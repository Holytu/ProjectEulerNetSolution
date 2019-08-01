#include <iostream>
using namespace std;

int countFactN(int num)
{
	int factN = 0;

	if(num % 2 == 0)
	{
		while(num % 2 == 0)
		{
			num = num / 2;
		}

		factN++;
	}
	int i = 3; 

	while(num > 1)
	{
		if(num % i == 0)
		{
			while(num % i == 0)
			{
				num = num / i;
			}
			
			factN = factN + 1;
		}

		if(factN > 4)
			return 1000;

		i+=2;
	}

	return factN;
}
bool FactorNumber(int n)
{
	int factN;

	factN = countFactN(n);

	if(factN != 4)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
int main()
{
	int n = 20;
	
	while(n < 200000)
	{
		bool a = FactorNumber(n);
		bool b = FactorNumber(n + 1);
		bool c = FactorNumber(n + 2);
		bool d = FactorNumber(n + 3);
		
		if ( a && b) 
		{
			if( c && d )
			{
				
					cout << "n = " << n << endl;
					cout << "a = " << a << endl;
					cout << "b = " << b << endl;
					cout << "c = " << c << endl;
					cout << "d = " << d << endl;
					break;
					
			}
		}
		n = n + 1;
	}
	
	

	return 0;
}