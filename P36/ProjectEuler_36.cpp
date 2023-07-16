#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//function defining wether number is a palindrom
bool isPalindromeInt(int number)
{
    vector <int> digits;
    int nCopy = number, multiplier = 1;

    //number can't be palindromic if it ends with 0
    // and in this particular case, it can't be even
    if (nCopy % 10 == 0 || nCopy % 2 == 0)
    {
        return false;
    }

    //insert digits into digits vector
    while (nCopy != 0)
    {
        digits.push_back(nCopy % 10);
        nCopy /= 10;
        multiplier *= 10;
    }

    multiplier /= 10;


    //create a mirrored version of number
    for (int i = 0; i < digits.size(); i++)
    {
        nCopy += digits[i] * multiplier;
        multiplier /= 10;
    }

    if (nCopy == number)
    {
        return true;
    }
    else return false;
}

bool isPalindromeString(string str)
{
    string str1;

    //delete all the 0 in front of the first 1
    while (str[0] == '0')
    {
        str.erase ( str.begin ());
    }

    for (int i = str.size(); i > 0; i--)
    {
        //str index is bigger by one than the string size
        str1 += str[i - 1];
    }

    if (str1 == str)
    {
        return true;
    }
    else return false;
}

int main()
{
    int sum = 0;
    vector <int> palindromes;

    for (int i = 0; i < 1000000; i++)
    {
        if (isPalindromeInt(i))
        {
            palindromes.push_back(i);
        }
    }

    for (int i = 0; i < palindromes.size(); i++)
    {
        //create a string and set it's content to binary version of palindromes[i]
        string binary = bitset <20> (palindromes[i]).to_string();

        if (isPalindromeString(binary))
        {
            sum += palindromes[i];
        }
    }

    cout << sum;
    return 0;
}
