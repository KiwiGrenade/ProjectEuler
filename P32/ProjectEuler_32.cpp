#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


//determine wether or not number is pandigital
bool isPandigital(int number, int multiplier)
{
    int product = number * multiplier;

    list <int> digits;
    list <int> form {1,2,3,4,5,6,7,8,9};

    //insert the digits of the number, multiplier and theyr product into list
    while (number != 0)
    {
        digits.push_back(number % 10);
        number /= 10;
    }
    while (multiplier != 0)
    {
        digits.push_back(multiplier % 10);
        multiplier /= 10;
    }
    while (product != 0)
    {
        digits.push_back(product % 10);
        product /= 10;
    }

    //check wether or not there are 9 digits in list and they are a permutation
    if (digits.size() == 9 && is_permutation (form.begin(),form.end(),digits.begin()))
    {
        return true;
    }
    else return false;
}

int main()
{
    list <int> products;
    for (int n = 2; n < 2000; n++)
    {
        for (int d = 2; d < n; d++)
        {
            if(isPandigital(n,d))
            {
                products.push_back (n*d);
            }
        }
    }

    int sum = 0;

    //sort and remove any repeating numbers
    products.sort();
    products.unique();

    for (auto v : products)
    {
        sum += v;
    }

    cout << sum;
    return 0;
}
