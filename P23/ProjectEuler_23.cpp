#include <iostream>

//sqrt() funtion
#include <math.h>

//vectors
#include <vector>

//time measurment
#include <chrono>
using namespace std;

//function that tells us wether the number is abundant or not
bool isAbundant(int number)
{
    //define sum as 0
    int sum=0;

    // increment as long as i is lesser of equal to root of a number
    for (int i=2;i<=sqrt(number);i++)
    {

        if (number%i==0)
        {

            //if i is the same as number/i ex: i=10, number=100
            if (i==(number/i))
            {
                sum+=i;
            }

            //else add the i and the number divided by i to the sum
            else
            {
                sum+=i+number/i;
            }
        }
    }
    return number < sum;
}

//function that tells us wether the number we operate on is
//a sum of two abundant numbers or not
bool iSum(int number)
{

    for (int x=0; x <=number/2; x++)
    {
        //if the number that we substract is abundant and
        //the number that we substract FROM is abundant
        if (isAbundant(x)==true && isAbundant(number-x)==true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //start measuring time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int sum=0;

    for (int x=0; x<28123; x++)
    {
        //if x is not a sum of two abundant numbers
        if (iSum(x)==false)
        {
            //add x to the sum
            sum+=x;
        }
    }
    cout << sum;

    //stop measuring time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /1000000.0<< std::endl;

    return 0;
}
