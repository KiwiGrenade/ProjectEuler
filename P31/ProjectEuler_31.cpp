/*This programme operates with help of a 2d array*/

#include <iostream>
#include <array>
using namespace std;

int main()
{
    array <int,8> coins {1,2,5,10,20,50,100,200};
    const int target = 200;
    int table [target + 1][coins.size()];

    //initialize first column with one, because
    //there is only one way to create a target with only 1p coins
    for (int i = 0; i <= target; i++)
    {
        table[i][0] = 1;
    }

    for (int i = 0; i <= target; i++)
    {
        for (int j = 1; j < coins.size(); j++)
        {
            //always rewrite combination number from left cell to current cell
            table[i][j] = table[i][j - 1];

            //if value of a coin is less or equal to wanted value
            if (coins[j] <= i)
                //add number of combinations of before calculated target value
                table[i][j] += table [i - coins[j]][j];
        }
    }

    cout << table[target][coins.size() - 1];

    return 0;
}
