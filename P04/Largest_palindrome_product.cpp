//A palindromic number reads the same both ways.
//The largest palindrome made from the product
//of two 2-digit numbers is 9009 = 91 × 99.

//Find the largest palindrome made from the product of two 3-digit numbers.

//Note that the same thing could be done converting the "palindromeCandidat"
//into a string, splitting it in half, reversing the second half, and than
//checking if the first and second halves are the same.
#include <iostream>
using namespace std;

bool isPalindrome(int x,int a) //this function determinates if the number is a palindrome in mathematical ways
{
    bool result=false;      //setting the result to 0 at the beginning
    int palindromeCandidat=x*a,digits[6],z=10;  //defining variables
    for (int i=0;i<6;i++)   //the for loop splits the number into single digits and inserts them into the array
    {
        digits[i]=palindromeCandidat%z; //inserting the last digit of the "number" into an array
        palindromeCandidat=palindromeCandidat/z;   //cutting off the last digit of the "number"
    }
    if (digits[0]==digits[5] && digits[1]==digits[4] && digits[2]==digits[3])
    {
        result=true;
    }
    return result;
}

int main()
{
    int biggestPalindromeNumber=0;
    for (int x=100;x<1000;x++)              //first digit
    {
        for (int a=100;a<1000;a++)          //second digit
        {
            if (isPalindrome(x,a)==true)
            {
                //cout << x*a << '\n';
                if (x*a>biggestPalindromeNumber)
                {
                    biggestPalindromeNumber=x*a;
                }
                else{}
            }
            else{}
        }
    }
    cout << biggestPalindromeNumber;
    return 0;
}
