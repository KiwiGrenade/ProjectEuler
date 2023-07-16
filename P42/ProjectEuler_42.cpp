#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//function
int word_value (string word)
{
    int value = 0;
    for (auto c : word)
    {
        switch (c)
        {
            case 'A': value += 1;break;
            case 'B': value += 2;break;
            case 'C': value += 3;break;
            case 'D': value += 4;break;
            case 'E': value += 5;break;
            case 'F': value += 6;break;
            case 'G': value += 7;break;
            case 'H': value += 8;break;
            case 'I': value += 9;break;
            case 'J': value += 10;break;
            case 'K': value += 11;break;
            case 'L': value += 12;break;
            case 'M': value += 13;break;
            case 'N': value += 14;break;
            case 'O': value += 15;break;
            case 'P': value += 16;break;
            case 'Q': value += 17;break;
            case 'R': value += 18;break;
            case 'S': value += 19;break;
            case 'T': value += 20;break;
            case 'U': value += 21;break;
            case 'V': value += 22;break;
            case 'W': value += 23;break;
            case 'X': value += 24;break;
            case 'Y': value += 25;break;
            case 'Z': value += 26;break;
        }
    }
    return value;
}

bool is_triangle (int v)
{
    //d is delta in quadratic equations
    double d = 1 + 8 * v, n;

    n = (1 + sqrt(d)) / 2;

    //fmod is a modulo function for variables of type double
    if (fmod(n, 1.0) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    ifstream file;
    string line;
    int i = 0;
    file.open("words.txt", std::ifstream::in);
    while (getline(file, line, ','))
    {
        //erase the quotation marks
        line.erase(line.begin());
        line.erase(line.end() - 1);

        if (is_triangle(word_value(line)))
        {
            i++;
        }
    }
    file.close();
    cout << i;
    return 0;
}
