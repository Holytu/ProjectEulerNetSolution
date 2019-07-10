#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a , b , c , temp;
	bool flag = false ;
	for( a = 1 ; a < 1000 ; a++)
	{
		flag = false ;
		for ( b = a + 1 ; b < 1000 ; b++)
		{
			flag = false ;
			for ( c = b + 1 ; c < 1000 ; c++)
			{
				int x = c * c - a * a - b * b;

				if ( x == 0 && (a + b + c ) == 1000)
				{
					cout<<"a = "<<a<<", b = "<<b<<", c = "<<c;
					flag = true;
					break;
				}
			}
			if( flag )
			{
				break;
			}
		}
		if( flag )
		{
			break;
		}
	}
	cout<< endl;
	cout << a * b * c;
	return 0;
}