//By listing the first six prime numbers:
//2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10001st prime number?


#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long i=2;
    int count=2;
    while (count<10001)
    {
        for (long x=2; x*x<=i; x++)
            {
                    if(i % x == 0)
                    {
                        break;
                    }
                    else if (x+1 > sqrt(i))
                    {
                        count++;
                    }
            }
        i++;
    }
    cout << i-1;
    return 0;
}


/*

Three ways:

1.

int main ()
{
    for (int i=2; i<100; i++)
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0)
                break;
            else if (j+1 > sqrt(i)) {
                cout << i << " ";

            }

        }

    return 0;
}

2.

int main ()
{
    for (int i=2; i<100; i++)
    {
        bool prime=true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) cout << i << " ";
    }
    return 0;
}

3.

#include <vector>
int main()
{
    std::vector<int> primes;
    primes.push_back(2);
    for(int i=3; i < 100; i++)
    {
        bool prime=true;
        for(int j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            primes.push_back(i);
            cout << i << " ";
        }
    }

    return 0;
}*/
