#include <iostream>
#include <math.h>
using namespace std;
bool palindrome(int n)
{
	int num[6] = {};
	int i = 0, j;// Rotate
	int tail;
	int flag = 1;
	while(n / 10 > 0)
	{
		num[i] = n % 10;
		n = n / 10;
		i++;
	}
	num[i] = n;
	tail = i;

	/*for (i = 0; i < tail+1 ; i++)
	{
		cout<<num[i]<<" "<<endl;
	}*/

	for(i = 0, j = tail ; i <= j ; i++, j--)
	{
		if(num[i] != num[j])
		{
			flag = 0;
			break;
		}
	}

	if(flag)
		return true;
	return false;
}
void GenerateNum()
{
	int num = 0;
	int x, y;
	for (int i = 999; i > 100; i--)
	{
		for (int j = 999; j > 100; j--)
		{
			if(palindrome( i * j ) == true)
			{
				if(num < i * j)
				{
					num = i * j;
					x = i;
					y = j;
				}
			}
		}
	}
	cout<<num<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
}

int main()
{
	//CheckDigitNum(10013);
	//palindrome(10013);
	GenerateNum();
	return 0;
}