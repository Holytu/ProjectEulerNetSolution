#include <iostream>

using namespace std;
int main()
{
	for (int i = 2520; ; i+=2)
	{
		int count = 0;
		for (int j = 2; j <= 20 ; j++)
		{
			if(i % j != 0)
			{
				break;
			}
			else
			{
				count++;
			}
		}
		if(count == (20 - 1))
		{
			cout<<i<<endl;
			break;
		}
	}

	return 0;
	
}