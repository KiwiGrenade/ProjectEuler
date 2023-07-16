//The sum of the squares of the first ten natural numbers is,
//12 + 22 + ... + 102 = 385
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)2 = 552 = 3025
//Hence the difference between the sum of the squares of the first
//ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//Find the difference between the sum of the squares of the first
//one hundred natural numbers and the square of the sum.


#include <iostream>
using namespace std;

int sumOfSquares(int max_cap)
{
    int sum=0;
    for (int i=1;i<=max_cap;i++)
    {
        sum+=i*i;
    }
    return sum;
}

int squareOfSum(int max_cap)
{
    int square=0,sum=0;
    for (int i=1;i<=max_cap;i++)
    {
        sum+=i;
    }
    square=sum*sum;
    return square;
}

int main()
{
    cout << squareOfSum(100)-sumOfSquares(100);
    return 0;
}
