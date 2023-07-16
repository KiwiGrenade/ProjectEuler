#include <iostream>
#include <math.h>
using namespace std;


//function that finds and sums the proper divisors of a number
int divSum(int number)
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


    return sum+1;
}

int main()
{
    //initialize the sum variable and set it's value to zero
    long int sum=0;

    //for loop
    for (int i=0; i<10000;i++)
    {
        {
            //check if i and divSum(i) is an ambicable pair
            //and if i and divSum(i) aren't the same number
            //ex 6 or 28
            if (i==divSum(divSum(i)) && i!=divSum(i))
            {
                //add both i and divSum(i) to the sum
                sum+=i+divSum(i);
            }
        }
    }


    //now you need to divide by 2, becouse every number was added to the sum 2 times
    cout << sum/2;
    return 0;
}
