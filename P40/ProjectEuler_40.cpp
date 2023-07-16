#include <iostream>
using namespace std;


//function for counting digits in a number
int d_counter(int n)
{
    int c = 0;
    while (n > 0)
    {
        n /= 10;
        c++;
    }
    return c;
}

int main()
{
    int  d_sum = 0, checkpoint = 1000000, value = 1, n = 0;

    //see which number has the milionth digit
    //and add the remaining digits of the number
    while (d_sum < 1000000)
    {
        n++;
        d_sum += d_counter(n);
    }


    for (; n > 0; n--)
    {
        for (int nCopy = n; nCopy > 0; nCopy /= 10, d_sum--)
        {
            int digit = nCopy % 10;
            if (d_sum == checkpoint && checkpoint > 0)
            {
                value *= digit;
                checkpoint/=10;
            }
        }
    }
    cout << value;
    return 0;
}
