#include <iostream>
#include <vector>
using namespace std;


//numerator is the number that is divided by x
// denominator is the x
// ex. numerator / denominator
bool isNonTrivial(float numerator, float denominator)
{
    vector <float> numDigits,denDigits;
    int numeratorCopy = numerator, denominatorCopy = denominator;

    //insert the digits into vectors
    while (numeratorCopy != 0)
    {
        numDigits.push_back(numeratorCopy % 10);
        numeratorCopy /= 10;
    }
    while (denominatorCopy != 0)
    {
        denDigits.push_back(denominatorCopy % 10);
        denominatorCopy /= 10;
    }

    //check if a one of the digits in numerator is the same as denominator
    if (numDigits[0] == denDigits[0])
    {
        //check wether the product of these divisions is the same
        if (numDigits[1] / denDigits[1] == numerator / denominator)
        {
            return 1;
        }
        else return 0;
    }
    if (numDigits[1] == denDigits[1])
    {
        if (numDigits[0] / denDigits[0] == numerator / denominator)
        {
            return 1;
        }
        else return 0;
    }
    if (numDigits[0] == denDigits[1])
    {
        if (numDigits[1] / denDigits[0] == numerator / denominator)
        {
            return 1;
        }
        else return 0;
    }
    if (numDigits[1] == denDigits[0])
    {
        if (numDigits[0] / denDigits[1] == numerator / denominator)
        {
            return 1;
        }
        else return 0;
    }
    return 0;
}

int main()
{

    // i is a numerator and j is a denominator
    vector <int> numerators, denominators;

    //the numberator is first, because it always has to be smaller than denominator
    for (int i = 10; i < 99; i++)
    {
        for ( int j = i + 1; j <= 99; j++)
        {
            if (i % 10 == 0 || j % 10 ==0);
            else if (isNonTrivial(i,j))
            {
                numerators.push_back(i);
                denominators.push_back(j);
            }
        }
    }

    double finalNumerator = 1, finalDenominator = 1;

    for (int i = 0; i < numerators.size(); i++)
    {
        finalNumerator *= numerators[i];
        finalDenominator *= denominators[i];
    }

    double product = finalNumerator / finalDenominator;
    cout << product;
    return 0;
}
