#include <iostream>
#include <cmath>
using namespace std;

bool is_pentagonal(long long n)
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
    bool not_found = true;
    int i = 143;

    while(not_found)
    {
        i += 2;
        long long h = i * (2 * i - 1);
        if (is_pentagonal(h))
        {
            cout << h;
            not_found = false;
            break;
        }
    }
    return 0;
}
