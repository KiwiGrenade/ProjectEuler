#include <iostream>
using namespace std;
int main()
{
    int sequenceLength = 0,divider;
    for (int i = 1000; i > 0; i--)
    {
        //sequence length can not be smaller than the number divider ("i")
        //becouse the sequence length of 1/d can't be greater than d-1
        //therefore we can stop the search once found sequence length
        //is greater than divider ("i")
        if (sequenceLength >= i)
        {
            break;
        }

        //here we will store the position as a variable of a list so that
        //the value will be the list's index
        int position = 0,value = 1;
        int foundRemainders[1000]{0};

        //as long as the value of the remainder wasn't yet changed
        //and value equal to 0
        while(foundRemainders[value] == 0 && value != 0)
        {
            foundRemainders[value] = position;
            value *= 10;
            value %= i;
            position++;
        }
        //substract the previous position of specific value from
        //the primal position of the value
        if(position - foundRemainders[value] > sequenceLength)
        {
            sequenceLength = position - foundRemainders[value];
            divider=i;
        }
    }
    cout << divider;
    return 0;
}
