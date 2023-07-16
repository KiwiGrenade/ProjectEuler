#include <iostream>
#include <list>
#include <vector>
using namespace std;

//primes calculating function
list <int> eSieve(int n)
{
    list <int> primeList;
    vector <bool> prime(n,true);

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
            primeList.push_front(i);
        }
    }
    return primeList;
}

//pandigital checking function
bool isPandigital(int n)
{
    int digits = 0; int count = 0; int tmp;

    while (n > 0)
    {
        tmp = digits;

        //using bit shift i change the bit that index is corresponding to the digits value
        //ex. we take digit "7" and change the sixth bit in "tmp" variable to one
        digits |= 1 << (n % 10) - 1;

        //if in any of the iterations one of the bits won't change
        //(that means the bit corresponding to that digit is already true, so the digits repeats itself)
        if (tmp == digits)
        {
            return false;
        }

        count++;
        n /= 10;
    }

    //on the right we create a variable with all the bits turned to true
    //ex.
    //number 1234 has to look like this in binary 1111, where the first one to the right is responsible for one in 1234, and second for two
    //number 1234 is pandigital, but 1235 is not as by definition
    //"pandigital number is an integer that in a given base has among its significant digits each digit used in the base at least once"
    return digits == (1 << count) - 1;
}

int main()
{
    list <int> primes;

    primes = eSieve(7654321);
    for (auto c : primes)
    {
        if (isPandigital(c))
        {
            cout << c;
            break;
        }
    }
    return 0;
}
