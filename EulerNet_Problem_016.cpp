#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	int arr[500]={};
	int sum = 0;
	arr[0] = 1;

	for(int i = 1; i < 1001; i++)
	{
		arr[0] = 2 * arr[0];

		for(int j = 1; j < 500; j++)
		{
			arr[j] = arr[j] * 2 + arr[j - 1] / 10;
		}

		for(int k = 0; k < 500; k++)
		{
			arr[k] = arr[k] % 10;
		}
	}

	for (int i = 0 ; i < 500 ; i++)
		sum = sum + arr[i];

	cout<<sum;

	return 0;
}
