#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool is_pentagonal(int n)
{
    double d = (6 * n) + 0.25;
    if (fmod(((0.5 + sqrt(d)) / 3), 1.0) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int i = 1;
    bool not_found = true;
    while (not_found)
    {
        i++;
        int n = i * (3 * i - 1) / 2;

        for (int j = i - 1; j > 0; j --)
        {
            int m = j * (3 * j - 1) / 2;
            if (is_pentagonal(n + m) && is_pentagonal(n - m))
            {
                cout << n - m;
                not_found = false;
                break;
            }
        }
    }
    return 0;
}
