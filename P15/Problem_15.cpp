#include <iostream>

using namespace std;

int main()
{
    const int gridSize=20;
    long long int grid[gridSize][gridSize];
    for (int i=0;i<gridSize;i++)//zainicjalizowanie "obreczy" kostki liczbai rosnacymi
    {
        grid[i][0]=i+2;
        grid[0][i]=i+2;
    }
    for (int s=1;s<gridSize;s++)
    {
        for (int n=1;n<gridSize;n++)//algorytm ten przesuwa grid[n][s]-celownik,
                                    //i wypelnia oczka
        {
            grid[n][s]=grid[n-1][s]+grid[n][s-1];//grid[1][1]=grid[0][1]+grid[1][0];
        }
    }
    cout << grid[gridSize-1][gridSize-1];
    return 0;
}
