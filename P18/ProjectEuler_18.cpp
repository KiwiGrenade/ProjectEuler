#include <iostream>
#include <fstream>
#include <list>
//stoi funtion
#include <algorithm>
using namespace std;

int main()
{
    string number;
    list <int> number_list;
    ifstream file;

    file.open("triangle.txt", ifstream::in);

    //extract  the numbers in the file
    while (getline(file, number, ','))
    {
        if (number[0] == '0')
        {
            number.erase(0,1);
        }
        number_list.push_back(stoi(number));
    }
    file.close();

    //create an array to store the numbers
    int pyramid[15][15]{0};

    //place the numbers in the array like a pyramid
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            pyramid[i][j] = *number_list.begin();
            number_list.pop_front();
        }
    }


    for (int i = 13; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            //see which number below is bigger and add it to the original number
            //repeat for every number of the pyramid, except the very bottom ones
            //they are already maxed
            pyramid[i][j] += max(pyramid[i + 1][j], pyramid[i + 1][j + 1]);
        }
    }


    cout << pyramid[0][0];
    return 0;
}
