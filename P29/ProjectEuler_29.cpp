#include <iostream>
#include <cmath>
#include <set>
using namespace std;

//main problem with this Problem is that i didn't know that with the use of type double variable
//the computer will actually see the differance between the numbers, even though it is impossible
//for long long type variables
int main()
{
    set <double> powSet;
    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            double result = pow (a,b);
            cout << result << '\n';
            powSet.insert(result);
        }
    }
    cout << powSet.size();
    return 0;
}
