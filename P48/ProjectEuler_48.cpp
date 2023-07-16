#include <iostream>
using namespace std;
#define D_NUMBER 10000000000;
/* We get n last digits of a number by dividing the number with modulo 10^n.
Modulo operation is łączna i przemienna, so we in opposition to dividing the wole
number, we can divide the numbers it is composed of by modulo 10^n*/

int main()
{
    long long int sum = 0, result = 0;
    for (int i = 1; i < 1000; i++)
    {
        if (i%10 != 0)
        {
            sum = i;
            for (int j = 1; j < i; j++)
            {
                //multiply modulo n
                sum = (sum * i) % D_NUMBER;
            }
            //add modulo n
            result = (result + sum) % D_NUMBER;
            sum = 0;
        }
    }
    cout << result;
    return 0;
}
