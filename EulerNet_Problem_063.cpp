#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class PE0063
{
public:
	int arr[1000];
	int LengthEqualPowTimes();
	
private:
	vector<int> digit_vec;
	
	void adjustDigit_vec(int arr[]);
	vector<int> Pow2Vec(int x , int y);
	
};
int PE0063::LengthEqualPowTimes()
{
	int number = 0; 

	for (int y = 1 ; y < 100 ; y++ )
	{
		for (int x = 1 ; x < 10 ; x++ )
		{
			vector<int> va = Pow2Vec( x , y );

			if( va.size() == y )
			{
				number++;
			}
		}
	}

	return number;
}
void PE0063::adjustDigit_vec(int arr[])
{
	for (int k = 0 ; k < 1000 - 1 ; k++ )
	{
		arr[ k + 1 ] = arr[ k + 1 ] + arr[ k ] / 10 ;
		arr[ k ] = arr[ k ] % 10; 
	}
}
vector<int> PE0063::Pow2Vec(int x , int y)
{
	for (int i = 0 ; i < 1000 ; i++ )
		arr[i] = 0;
	
	arr[0] = 1;

	for (int i = 1 ; i <= y ; i++ )
	{
		for (int k = 0 ; k < 1000 ; k++ )
		{
			arr[k] = arr[k] * x ;
		}

		adjustDigit_vec(arr);
	}

	int j ;
	for ( j = 1000 - 1 ; j >= 0 && arr[j] == 0 ; j--) {}

	vector<int> digit_vec(j+1);

	for (int k = 0; k <= j ; k++ )
	{
		digit_vec[k] = arr[k];
	}
	return digit_vec;
}
int main()
{
	PE0063 pe0063;
	cout << pe0063.LengthEqualPowTimes() << endl;
	return 0;
}

