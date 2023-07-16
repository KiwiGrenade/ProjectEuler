/*This programme operates on 1d array*/
#include <iostream>
#include <array>
using namespace std;

int main()
{
    array <int,8> coins {1,2,5,10,20,50,100,200};
    const int target = 200;
    int table [target + 1] {0};

    //initialize first cell of the table with one, because
    //there is only one way to create a targetValue 1 with 1p coin
    table[0] = 1;

    //this for loop chagnes the coin that we operate on
    for (int i = 0; i < coins.size(); i++)
    {
        //this loop changes the number of combinations
        //as we can see, we don't operate on values smaller
        //than the value of the coin
        for (int j = coins[i]; j <= target; j++)
        {
            table[j] += table[j - coins[i]];
        }
    }
    for (int i = 0; i < target; i++)
    {
        cout << table[i] << '\n';
    }
    cout << table[target];
    return 0;
}
