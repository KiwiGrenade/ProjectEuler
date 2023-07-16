#include <iostream>

//next_permutation()
#include <algorithm>

using namespace std;

int main()
{
    //next_permutation() treats numbers as digits, so we need
    //to separate every digit that we want to use and dump it
    //into a list of integers
    int digits[]{0,1,2,3,4,5,6,7,8,9};

    //we call the function milion 999999 times, becouse
    //the digits we wrote down were the first permutation
    for (int i=1;i<1000000;i++)
    {
        next_permutation (digits,digits+10);
    }

    //now we just print out the numbers
    for (int i=0;i<10;i++)
    {
        cout << digits[i];
    }
    return 0;
}
