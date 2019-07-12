#include <iostream>
#include <array>
#include <string.h>
using namespace std;

int main()
{
	char str1[100] = "933262154439441526816992388562667004907";
	char str2[100] = "15968264381621468592963895217599993229915608941";
	char str3[100] = "463976156518286253697920827223758251185210916864000000000000000000000000";

	int tail_str1, tail_str2, tail_str3 ;
	double sum = 0;

	for (int i = 0 ; str1[i] != '\0' ; i++)
		tail_str1 = i ;
	for (int i = 0 ; str2[i] != '\0' ; i++)
		tail_str2 = i;
	for (int i = 0 ; str3[i] != '\0' ; i++)
		tail_str3 = i;

	for (int i = 0 ; i <= tail_str1 ; i++)
	{
		sum = sum + ( str1[i] - '0' );
	}

	for (int i = 0 ; i <= tail_str2 ; i++)
	{
		sum = sum + ( str2[i] - '0' );
	}

	for (int i = 0 ; i <= tail_str3 ; i++)
	{
		sum = sum + ( str3[i] - '0' );
	}

	cout << sum << endl;
	

	return 0;
}