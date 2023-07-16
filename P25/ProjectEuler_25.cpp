/*
Warning! Warning!
This program was written with the use of an external library called GNU MP*/

#include <iostream>
#include <gmp.h>
using namespace std;

int main()
{
    mpz_t number;
    mpz_init_set_str (number,"0",10);
    int n=0;
    while(mpz_sizeinbase(number,10)<1000)
    {
    mpz_fib_ui(number,n);
    n++;
    }
    cout << n;
    mpz_clear (number);
    return 0;
}
