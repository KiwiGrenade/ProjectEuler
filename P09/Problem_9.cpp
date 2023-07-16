/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
using namespace std;

int main()
{
    int a=1,b=1,c=1;
    for (c;c < 1000;c++)
    {
        //cout << "c = " << c << '\n';
        b=0;
        for (b;b < c;b++)
        {
            //cout << "b = " << b << '\n';
            a=0;
            for (a;a < b;a++)
            {
                //cout << "a = " << a << '\n';
                if ((a*a)+(b*b)==(c*c) && a+b+c==1000)
                {
                    cout << a*b*c; break;
                }
            }
        }
    }
    return 0;
}
