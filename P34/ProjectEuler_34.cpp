#include <iostream>
#include <vector>
using namespace std;

//factorial funtion
long factorial(long number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    if (number == 2)
    {
        return 2;
    }
    return number * factorial(number - 1);
}

//function determining wether number is a curious number
bool isCurious(long long number)
{
    vector <int> digits;
    long long numberCopy = number;
    long long sum = 0;

    //insert number digits into 'digits' vector
    while (number != 0)
    {
        digits.push_back(number % 10);
        number/=10;
    }

    //sum the number digits factorial
    for (int i = 0; i < digits.size(); i++)
    {
        sum += factorial(digits[i]);
    }

    if (sum == numberCopy)
    {
        return true;
    }
    else return false;
}
int main()
{
    long long sum = 0;
    for(long int i = 3; i < 400000; i++)
    {
        if (isCurious(i))
        {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
