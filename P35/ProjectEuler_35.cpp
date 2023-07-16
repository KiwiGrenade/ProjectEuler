#include <iostream>
#include <set>
//include memset()
#include <cstring>
#include <list>

using namespace std;

/*  'primes' is a set containing all the primes that haven't been proven circluar.
    Becouse we want to remove the circluar primes form that list, it need to be a global variable
    I simply don't know how to make it something else. */
set <int> primes;


//Eratosthenes Sieve that returns a 'set' of 'ints'
//with all the primes in range 'n'
set <int> eSieve(int n)
{
    set <int> primeList;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int i = 2; i*i <= n; i++)
    {
        if (prime[i] == true)
        {
            for ( int j = i*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            primeList.insert(i);
        }
    }
    return primeList;
}


//Function for finding circle primes. More about circle primes on wikipedia.
int isCirclePrime(int prime)
{
    //multiplier multiplies the last digit of a number, so that it end's up at
    //the front of a number
    int multiplier = 1, number = prime, count = 0, d;

    while (number > 0)
    {
        //d is now the last digit the number
        d = number % 10;

        //if one of the digits is divisable by 2 or 5, the prime isn't a
        //circle prime, becouse the digit will ultimately end up being the last digit
        //which makes the number divisable by 2 or 5, therefore not a prime
        if (d % 2 == 0 || d % 5 == 0)
        {
            primes.erase(prime);
            return 0;
        }
        number /= 10;
        multiplier *= 10;
        count++;
    }
    //multiplier needs to be a 10^d-1, where d is the number of digits in a prime
    multiplier /= 10;

    //reset the number
    number = prime;

    set <int> foundCircluarPrimes;
    for (int i = 0; i < count; i++)
    {
        //if the number is a prime
        if (primes.find(number) != primes.end())
        {
            //add it to the set of 'foundCircluarPrimes'
            foundCircluarPrimes.insert(number);
            //and erase it from the set of primes
            primes.erase(number);
        }
        //if the number isn't a prime, return 0
        else if (foundCircluarPrimes.find(number) == foundCircluarPrimes.end())
        {
            return 0;
        }

        //d is the last digit of the number
        d = number % 10;
        //make it the first digit
        number = d * multiplier + number / 10;
    }
    return foundCircluarPrimes.size();
}


int main()
{
    int NCPrimes = 2;
    primes = eSieve(1000000);
    //special cases
    primes.erase(2);
    primes.erase(5);

    //becouse primes is a global variable, it's size is constantly changing, so it can't
    //be a limiter of a for() loop
    int n = primes.size();

    for (int i = 0; i < n; i++)
    {
        //set.begin() returns an iterator to the beggining of a set, but we need it's value
        NCPrimes += isCirclePrime (*primes.begin());
    }
    cout << NCPrimes;
    return 0;
}
