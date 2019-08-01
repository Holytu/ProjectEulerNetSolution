#include <iostream>
#include <cmath>
using namespace std;
unsigned long long mode = pow(10, 10);
unsigned long long modeCompute(unsigned long long num)
{
	unsigned long long t = num, answer = 1;

	while(t > 0)
	{
		answer = answer * num;
		if(answer >= mode)
			answer = answer % mode;

		t--;
	}
	return answer;
}
int main()
{
	//cout << mode << endl;

	int num = 1; 
	unsigned long long answer = 0;

	while(num < 1001)
	{
		unsigned long long a = modeCompute(num);
		
		answer = answer + a;

		if(answer >= mode)
			answer = answer % mode;

		num++;
	}
	cout << answer << endl;
	cout << answer % mode << endl;
	cout << mode << endl;
	return 0;
}