/*This programme operates using a squence approach. Basically the distance
between two numbers in the corners increases by two every time you get to all
four corners */
#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    //by defoult, the distance betweenLimit two numbers is 2
    //and the distance is 0, becouse there are no numbers between 1 and 2
    int cornerNumber = 0,distanceLimit = 2,distance = 0;
    for (int i = 1; i < 1001*1001 + 1; i++)
    {
        //if i is the number in the corner
        if (distance == 0)
        {
            cornerNumber++;
            sum += i;
            distance = distanceLimit;
        }
        //if you found all the corners
        if (cornerNumber == 4)
        {
            distanceLimit += 2;
            number = 0;
        }
        distance--;
    }
    cout << sum;
    return 0;
}
