#include <iostream>
#include <vector>
using namespace std;
class PE0057
{
private:
    vector<int> getNewNumerator(vector<int>& tmp_num_vec , int multiple , vector<int>& tmp_den_vec);
public:
    int getNumberOfFractions(int expansions);
};

vector<int> PE0057::getNewNumerator(vector<int>& tmp_num_vec , int multiple , vector<int>& tmp_den_vec)
{
    int size_n = tmp_num_vec.size();
    int size_d = tmp_den_vec.size();

    vector<int> new_num_vec;

    if( size_d > size_n )
    {
        for (int i = 0 ; i < size_n ; i++ )
        {
            new_num_vec.push_back( multiple * tmp_den_vec[i] + tmp_num_vec[i] );
        }

        for (int i = size_n ; i < size_d ; i++ )
        {
            new_num_vec.push_back( multiple * tmp_den_vec[i] );
        }
    }
    else if ( size_d < size_n )
    {
        for (int i = 0 ; i < size_d ; i++ )
        {
            new_num_vec.push_back( multiple * tmp_den_vec[i] + tmp_num_vec[i] );
        }
        for (int i = size_d ; i < size_n ; i++ )
        {
            new_num_vec.push_back( tmp_num_vec[i] );
        }

    }
    else if (size_d == size_n )
    {
        for (int i = 0 ; i < size_n ; i++ )
        {
            new_num_vec.push_back( multiple * tmp_den_vec[i] + tmp_num_vec[i] );
        }
    }

    int size_new = new_num_vec.size(); 

    for (int i = 0 ; i < size_new ; i++ )
    {
        if (new_num_vec[i] >= 10 )
        {
            if( i == size_new - 1 )
            {
                new_num_vec.push_back( new_num_vec[ i ] / 10);
                new_num_vec[ i ] = new_num_vec[ i ] % 10;
            }
            else 
            {
                new_num_vec[ i + 1 ] = new_num_vec[ i + 1 ] + new_num_vec[ i ] / 10;
                new_num_vec[ i ] = new_num_vec[ i ] % 10; 
            }
        }
    }

    return new_num_vec;
}

int PE0057::getNumberOfFractions(int expansions)
{
    int NumberOfFractions = 0;

    vector<int> num_vec;
    vector<int> den_vec;

    vector<int> tmp_num_vec;
    vector<int> tmp_den_vec;

    tmp_num_vec.push_back(0);
    tmp_den_vec.push_back(1);

    for (int i = 1 ; i <= expansions ; i++ )
    {
        num_vec = getNewNumerator(tmp_num_vec , 2 , tmp_den_vec);
        den_vec = tmp_den_vec;

        tmp_num_vec = den_vec;
        tmp_den_vec = num_vec;

        num_vec = getNewNumerator(tmp_num_vec , 1 , tmp_den_vec);
        den_vec = tmp_den_vec;

        if( num_vec.size() > den_vec.size() )
        {
            NumberOfFractions++;
        }
    }

    return NumberOfFractions;
}

int main()
{
    PE0057 pe0057;

    cout << pe0057.getNumberOfFractions(1000) << endl;

    return 0;
}