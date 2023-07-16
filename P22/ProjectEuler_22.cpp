#include <iostream>


//include the fstream library for file stream manipulation
#include <fstream>

//include the vector library for creating the array of strings
#include <vector>

//include the algorithm library for accessing sort()
#include <algorithm>
using namespace std;

//create a bool funtion for comparing two strings
bool mycomp (string a, string b)
{
    return a<b;
}

//create a function to alphabetically sort the list of the names
vector <string> ABCsort (vector <string> a)
{
    //sort the list from beggining to the end with help of the mycomp()
    sort(a.begin(), a.end(), mycomp);
    return a;
}

//create a function for evaluating names
int nVal (string name,int multiplier)
{
    int letterValue=0,letterValueSum=0;
    for (int i=0; i < name.size(); i++)
    {
        /*create a switch that estimate the value of a character
        and remember, that each name starts with a capital, so you need
        to create values for capitals too*/
        switch (name[i])
        {
            case 'a': letterValue=1;break;
            case 'b': letterValue=2;break;
            case 'c': letterValue=3;break;
            case 'd': letterValue=4;break;
            case 'e': letterValue=5;break;
            case 'f': letterValue=6;break;
            case 'g': letterValue=7;break;
            case 'h': letterValue=8;break;
            case 'i': letterValue=9;break;
            case 'j': letterValue=10;break;
            case 'k': letterValue=11;break;
            case 'l': letterValue=12;break;
            case 'm': letterValue=13;break;
            case 'n': letterValue=14;break;
            case 'o': letterValue=15;break;
            case 'p': letterValue=16;break;
            case 'q': letterValue=17;break;
            case 'r': letterValue=18;break;
            case 's': letterValue=19;break;
            case 't': letterValue=20;break;
            case 'u': letterValue=21;break;
            case 'v': letterValue=22;break;
            case 'w': letterValue=23;break;
            case 'x': letterValue=24;break;
            case 'y': letterValue=25;break;
            case 'z': letterValue=26;break;
            case 'A': letterValue=1;break;
            case 'B': letterValue=2;break;
            case 'C': letterValue=3;break;
            case 'D': letterValue=4;break;
            case 'E': letterValue=5;break;
            case 'F': letterValue=6;break;
            case 'G': letterValue=7;break;
            case 'H': letterValue=8;break;
            case 'I': letterValue=9;break;
            case 'J': letterValue=10;break;
            case 'K': letterValue=11;break;
            case 'L': letterValue=12;break;
            case 'M': letterValue=13;break;
            case 'N': letterValue=14;break;
            case 'O': letterValue=15;break;
            case 'P': letterValue=16;break;
            case 'Q': letterValue=17;break;
            case 'R': letterValue=18;break;
            case 'S': letterValue=19;break;
            case 'T': letterValue=20;break;
            case 'U': letterValue=21;break;
            case 'V': letterValue=22;break;
            case 'W': letterValue=23;break;
            case 'X': letterValue=24;break;
            case 'Y': letterValue=25;break;
            case 'Z': letterValue=26;break;
        }
        letterValueSum+=letterValue;
    }
    //return the name value
    return letterValueSum*(multiplier+1);
}


int main()
{
    ifstream nameList;
    string line;
    int i = 0;
    vector <string> list;
    signed long long int sum=0;

    //Load the "list"
    //create a stopper to stop getline()
    const char stopper = ',';

    //open the file
    nameList.open("names.txt",std::ifstream::in);

    //getline until you find the stopper
    while (getline(nameList, line, stopper))
    {
        //erase the first character
        line.erase(line.begin());

        //erase the penultimate character
        line.erase(line.end()-1);

        //push back the line
        list.push_back(line);
        i++;
    }

    //sort the "list"
    list=ABCsort(list);

    for (int x=0; x < list.size(); x++)
    {
        //add the value of a name to the list
        sum+=nVal(list[x],x);
    }
    nameList.close();
    cout << sum;
    return 0;
}
