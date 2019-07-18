#include <iostream>

using namespace std;
int num = 10;
long long CollatzSeq(long long x)
{
	int countPath = 1;

	while(x != 1 )
	{
		if(x & 1 )
			x = x * 3 + 1;
		else
			x = x / 2;

		countPath++;
	}

	return countPath;
}
int main(int argc, char const *argv[])
{
	long long NumberOfPath = 0;
	int Number = 0;

	
	for (long long i = 3 ; i < 1000000 ; i++)
	{
		long long x = CollatzSeq(i);
		if( NumberOfPath < x )
		{
			NumberOfPath = x;
			Number = i;
		}
	}
	
	
	cout<<"NumberOfPath : "<<NumberOfPath<<endl;
	cout<<"Number : "<<Number;
	
	/*
	cout<<CollatzSeq(10);
	*/

	return 0;
}
