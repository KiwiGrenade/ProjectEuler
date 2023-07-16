/*Second version of the programm is much faster and operates on a basis of creating
a list of abundant numbers, and then substracting them from the number that we operate on.*/
#include <iostream>

//sqrt() function
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
bool iSum(int number, vector <int> list)
{

    //variable that changes the substracted number
    int x=0;

    //a "while" loop that stops if the value of the variable that we substract
    //is of greater value than the number that we substract FROM
    while (list[x]<number)
    {
        //if the difference between two variables is an abundant number
        if (isAbundant(number-list[x])==true)
        {
            return true;
        }
        //increment x
        x++;
    }
    return false;
}

int main()
{
    //start measuring time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int sum=0;
    //list of abundant numbers
    vector <int> abNumList;

    //fill the list
    for (int i=0; i<28123; i++)
    {
        if (isAbundant(i)==true)
        {
            abNumList.push_back (i);
        }
    }


    for (int x=0; x<28123; x++)
    {
        //if the number is not a sum of two abundant numbers
        if (iSum(x,abNumList)==false)
        {
            //add the number to the sum
            sum+=x;
        }
    }
    cout << sum;

    //stop measuring time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << endl;

    return 0;
}
