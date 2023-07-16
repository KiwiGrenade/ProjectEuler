#include <iostream>
#include <map>
using namespace std;
int main()
{
    std::map <int, int> wValue;
    //map initialization
{
    wValue[0]=0;
    wValue[1]=3;
    wValue[2]=3;
    wValue[3]=5;
    wValue[4]=4;
    wValue[5]=4;
    wValue[6]=3;
    wValue[7]=5;
    wValue[8]=5;
    wValue[9]=4;
    wValue[10]=3;
    wValue[11]=6;
    wValue[12]=6;
    wValue[13]=8;
    wValue[14]=8;
    wValue[15]=7;
    wValue[16]=7;
    wValue[17]=9;
    wValue[18]=8;
    wValue[19]=8;
    wValue[20]=6;
    wValue[30]=6;
    wValue[40]=5;
    wValue[50]=5;
    wValue[60]=5;
    wValue[70]=7;
    wValue[80]=6;
    wValue[90]=6;
    wValue[100]=7;
    wValue[1000]=11;
}
int sum=0;
for (int i=1;i<10;i++)
{
    sum+=(wValue[i]*9001);
}
    cout << sum;
    return 0;
}
