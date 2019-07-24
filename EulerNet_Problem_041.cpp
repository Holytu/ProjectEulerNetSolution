#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime(unsigned int n)
{
	if(!(n & 1) && n > 2)
		return false;

	for (int i = 3 ; i * i <= n ; i+=2)
	{
		if(n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int num[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};// Answer is seven 
	unsigned int maxwell = 0;
	int index = 9;

	while(index > 0)
	{
		for (int k = 0 ; k < index ; k++)
		{
			num[k] = k + 1;
		}

		do
		{
			unsigned int sum = 0;

			if(num[index - 1] % 2 != 0)
			{
				sum = num[0];

				for (int i = 1; i < index; i++)
				{
					sum = sum * 10 + num[i];
				}

				if(isPrime(sum) == true)
				{
					//cout << "Yes\n" << endl;

					if(maxwell < sum)
						maxwell = sum;
				}
			}
		}
		while(next_permutation(num , num + 7));

		index = index - 1;
	}
	if(maxwell)
		cout << maxwell << "\n";
	else
		cout << "No prime number\n";

	return 0;
}