#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//algorithm that tests wether the number is correct and returns the number of it's multiplications ie n * 1, n * 3 etc
int isCorrect (int n)
{
    vector <int> digits;
    vector <int> form {1,2,3,4,5,6,7,8,9};
    int product[n];

    //create the products
    for (int i = 1; i < 5; i++)
    {
        product[i - 1] = i * n;
    }

    //create variable for storing the number of multiplications
    int cycleNumber = 0;
    while (digits.size() < 9)
    {
        if (product[cycleNumber] == 0)
        {
            cycleNumber++;
        }
        digits.push_back(product[cycleNumber] % 10);
        product[cycleNumber] /=10;
    }

    //if one of the products is so large that it exceeds the limit of 9 digits than the number is considered wrong
    if (product[cycleNumber] != 0 )
    {
        return 0;
    }

    if (is_permutation(form.begin(), form.end(), digits.begin()))
    {
        return cycleNumber;
    }

    return 0;
}

int main()
{
    int biggestSum = 0;
    for (int i = 9235; i < 9876 ; i++)
    {
        if (isCorrect(i)!=0)
        {
            int mulNumber = isCorrect(i);
            int number[mulNumber];

            for (int j = 1; j <= mulNumber+1;j++)
            {
                number[j-1] = i * j;
            }


            int sum = 0, m = 1;
            while (number[0] > 0)
            {
                if (number[mulNumber] == 0 )
                {
                    mulNumber--;
                }
                sum += (number[mulNumber] % 10) * m;
                number[mulNumber] /= 10;
                m *= 10;
            }

            if (sum > biggestSum)
            {
                biggestSum = sum;
            }
        }
    }
    cout << biggestSum;
    return 0;
}
