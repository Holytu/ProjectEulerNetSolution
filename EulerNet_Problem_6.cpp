#include <iostream>

using namespace std;
int main()
{
	long long int square_of_sum = 0 , sum_of_square = 0;
	for (int i = 1 ; i <= 100 ; i++)
	{
		square_of_sum = square_of_sum + i * i;
	}

	sum_of_square = 100 * 101 / 2;

	sum_of_square = sum_of_square * sum_of_square;

	cout << sum_of_square - square_of_sum <<endl ;
	return 0;
}