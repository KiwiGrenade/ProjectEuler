#include <iostream>
//include "The GNU Multiple Precision Arithmetic Library"
#include <gmp.h>
using namespace std;

void factorial (int n)
{
    //create variables of type mpz_t (SoD means the sum of digits)
    mpz_t sum,quo,SoD;

    //initialize the variables
    mpz_init (sum);
    mpz_init (quo);
    mpz_init (SoD);

    //set sum to value 1 and SoD to value 0
    mpz_set_ui(sum, 1);
    mpz_set_ui(SoD, 0);

    //basically n! (a factorial)
    for (int i=1; i<n+1;i++)
    {
        mpz_mul_si(sum,sum,i);
    }

    //loop for adding the sum's digits (300 is just a random number that is bigger than number of sum's digits)
    for (int i=0;i<300;i++)
    {
        //divide sum by ten and the reminder set as quo
        mpz_tdiv_r_ui (quo,sum,10);

        //add quo to the sum of digits
        mpz_add (SoD,SoD,quo);

        //divide sum by ten (it cuts off the last digit of the number)
        mpz_tdiv_q_ui (sum,sum,10);
    }
    //print out the solution
    cout << SoD << '\n';
}

int main ()
{
    factorial(100);
    return 0;
}
