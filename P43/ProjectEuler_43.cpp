#include <iostream>
#include <algorithm>
using namespace std;

//createing sub strings
int c_int(int d1, int d2, int d3)
{
    return d1 * 100 + d2 * 10 + d3;
}

//checking wether substrings are "right" (check projec teuler 43 for definiton)
bool is_right(int digits[])
{
    int divisors[] {2, 3, 5, 7, 11 , 13, 17};

    //check the first sub string with first divisor and iterate
    for (int i = 0; i <= 6; i++)
    {
        if (c_int(digits[i + 1], digits[i + 2], digits[i + 3]) % divisors[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int digits[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long sum = 0;
    while (next_permutation(digits, digits+10))
    {
        if (is_right(digits))
        {
            long long multiplier = 1000000000;
            for (auto c : digits)
            {
                //sum all the right pandigitals
                sum += c * multiplier;
                multiplier /= 10;
            }
        }
    }
    cout << sum;
    return 0;
}
