#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	fstream file;
	char word;
	int count = 0;
	int TriangleNum = 0;
	int flag = 0;
	int test = 0;
	string inputStr;

	file.open("EulerNet_Problem_042.txt", ios::in);

	if(!file)
	{
		cout <<"Error\n";
	}
	else
	{
		while( file.get(word) )
		{
			if(word == '"' && flag == 0)
			{
				count = 0 ;
				flag++;
			}
			else if(word == '"' && flag == 1)
			{
				count = count * 2;
				int x = sqrt(count);
				int y = x + 1;
				if(x * y == count)
				{
					TriangleNum++;
				}
				
				flag = 0;
			}
			else
			{
				count = count + ( word - 'A' ) + 1 ;
			}
		}
		cout << "TriangleNum = " << TriangleNum << endl;
		
		file.close();
	}
	return 0;
}
