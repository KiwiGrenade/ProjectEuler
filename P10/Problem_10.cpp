#include <iostream>
//include memset()

using namespace std;

/*  The function beneath is a representation of Eratosthenes Sieve, which is and algorithm for
finding primes by taking the smallest prime number 2 and removing all its multiplications.
Then doing the same with the next number in array, which is a prime too.*/
long long eSieve(int n)
{
    long long sum = 0;
    //create an boolean array
    bool prime[n+1];
    //and set all it's values to true
    memset(prime, true, sizeof(prime));

    for (int i = 2; i*i <= n; i++)
    {
        //if the number is a prime
        if (prime[i] == true)
        {
            //find all its multiplications in range n
            for ( int j = i*i; j <= n; j += i)
            {
                //and set their values to false
                prime[j] = false;
            }
        }
    }

    //now, sum all the numbers
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    cout << eSieve(2000000);
    return 0;
}
