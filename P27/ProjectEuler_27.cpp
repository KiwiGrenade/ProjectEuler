#include <iostream>
using namespace std;

//funtion determining whether the suspect is a prime
bool isPrime(int suspect)
{
    if (suspect <= 0)
    {
        return false;
    }
    for (int i=2; i*i <= suspect; i++)
    {
        if (suspect % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int maxcount = 0, max_a = 0, max_b = 0;

    // |b| < 1000 == -1000 < b < 1000
    for (int b=-1000; b < 1000; b++)
    {
        // |a| <=1000 == -1000 <= a <=1000
        for(int a = -1000; a <= 1000; a++)
        {
            int n = 0, number = 0, count = 0;
            do
            {
                //formula n^2+an+b
                number = (n*n) + (a*n) + b;
                n++;
                count++;
            }
            while(isPrime(number));
            if (count > maxcount)
            {
                maxcount = count;
                max_a = a;
                max_b = b;
            }
        }
    }
    cout << max_a * max_b;
    return 0;
}
