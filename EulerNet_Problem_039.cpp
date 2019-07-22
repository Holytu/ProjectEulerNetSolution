#include <iostream>
using namespace std;

int main()
{
	int i , j , k , p , max_num_P = 0, Big_P = 0;
	int sum_P[1000] = {0};

	for ( i = 1; i <= 333 ; i++)
	{
		for ( j = i + 1; j <= 666 ; j++)
		{
			for ( k = j + 1 ; k <= 1000 ; k++)
			{
				p = i + j + k;
				if( p  <= 1000 )
				{
					if( ( i * i + j * j ) == k * k)
					{
						//cout << "p = " << p << endl;
						sum_P[ p - 1 ]++;
					}

					if( max_num_P < sum_P[ p - 1 ] )
					{
						max_num_P = sum_P[ p - 1];
						Big_P = p;
					}
				}

				
				else
				{
					break;
				}
			}
		}
	}
	cout <<"Big_P = " << Big_P << endl;


    return 0;
}