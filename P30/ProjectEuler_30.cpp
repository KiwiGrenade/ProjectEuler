#include <iostream>
#include <cmath>
using namespace std;

bool isDistinct(int number)
{
    int d, sum = 0, pNumber = number;

    //sum all the digits to fifth power
    while(number > 0)
    {
        d = number % 10;
        number /= 10;
        sum += pow(d, 5);
    }

    //if the sum of the digits is the same as the number
    if (sum == pNumber)
    {
        return true;
    }
    return false;
}

int main()
{
    int sum = 0;
    for (int i = 2; i < 355000; i++)
    {
        if (isDistinct(i))
        {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
