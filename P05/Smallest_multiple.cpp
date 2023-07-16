//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

//Ok, so first thing is, you don't need to actualy try to divide the number by
//the numbers from 1 to 20, you just need to divide them by numbers from 11 to 20

#include <iostream>
using namespace std;

bool isEvenlyDiv(long number)//checking if the "number" is evenly divisible
                            //by the numbers from 11 to 20
{
    bool result=true;
    for (int i=11;i<=20;i++)
    {
        //cout <<i << '\n';
        if (Number%i!=0)
        {
            result=false;
            break;
        }
    }
    return result;
}

int main()
{
    for (long i=1; i<1000000000; i++)
    {
        if (isEvenlyDiv(i)==true)
        {
            cout << i; break;
        }
    }
    return 0;
}
