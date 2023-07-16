#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//primes calculating function
vector <int> eSieve(int n)
{
    vector <int> primeList;
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
            primeList.push_back(i);
        }
    }
    return primeList;
}

//primes checking function
bool isPrime(int n, vector <int> primeList)
{
    for (int i = 0; i < primeList.size();i++)
    {
        if (n == primeList[i])
        {
            return true;
        }
    }
    return false;
}

//truncatable numbers checking function
bool isTruncatable( int n, vector <int> primeList)
{
    //we don't need to check the n, because it already is a prime
    int nCopy = n / 10, mul = 1, counter = 0;

    while (nCopy > 0)
    {
        if (!isPrime(nCopy, primeList))
        {
            return false;
        }
        counter++;
        nCopy /= 10;
        mul *= 10;
    }

    //same applies here
    for (int i = 0; i < counter; i++)
    {
        n %= mul;
        if (!isPrime(n,primeList))
        {
            return false;
        }
        mul /= 10;
    }

    return true;
}

int main()
{
    //i = 5 because 2,3,5,7 aren't truncatable numbers
    int i = 5, counter = 0, sum = 0;
    vector <int> primes = eSieve(1000000);
    while (counter < 11)
    {
        if (isTruncatable(primes[i], primes))
        {
            counter++;
            sum += primes[i];
            cout << primes[i] << endl;
        }
        i++;
    }
    cout << sum;
    return 0;
}
