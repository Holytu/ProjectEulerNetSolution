#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string str = "";

string int2str(int &i)
{
    stringstream ss("");
    ss << i ;
    return ss.str();
}
void BuildArray()
{
    int i = 1;

    while(str.length() < 1000001)
    {
        string s = "";
        s = int2str(i);
        str = str + s;
        i++;
    }

}
int main()
{
    BuildArray();
    int d = 1 , sum = 1;
    for (int i = 1 ; i <= 7 ; i++)
    {
        sum = sum * (str[d - 1] -'0');
        d = d * 10;
    }
    cout << "sum = " << sum <<  endl;
    return 0;
}
