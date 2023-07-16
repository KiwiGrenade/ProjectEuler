/*It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?*/

#include <iostream>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

//Sieve of Eratosthenes (creating a list with primes)
list <int> eSieve(int limit)
{
    list <int> primeList;
    vector <bool> prime(limit, true);

    for (int i = 2; i*i <= limit; i++)
    {
        if (prime[i] == true)
        {
            for ( int j = i * i; j <= limit; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++)
    {
        if (prime[i])
        {
            primeList.push_front(i);
        }
    }
    return primeList;
}

//composite checking algorithm
bool isComposite(int n, int limit)
{
    list <int> primeList = eSieve(limit);

    int x = n;
    while (true)
    {
        x = n;

        //substract the prime form the number stored by x and divide it by 2
        x = (x - primeList.back()) / 2;
        //delete the prime from the list of primes
        primeList.pop_back();

        if (x < 0)
        {
            break;
        }

        //if the reminder of the square root of the number divided by 1 is equal to 0
        if (fmod(sqrt(x), 1) == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    int n = 1, i = 1;
    while (isComposite(n,100000))
    {
        //create an odd composite number
        n = i * 2 + 1;
        i++;
    }
    cout << n;
    return 0;
}
