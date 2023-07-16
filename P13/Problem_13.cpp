#include <iostream>
#include <fstream>
#include <gmp.h>
using namespace std;

int main()
{

    ifstream file;                                  //creating "file" variable
    file.open("Numbers.txt",std::ifstream::out);    //initiating and opening file

    if (file)   //if file is opened correctly, do:
    {
        mpz_t number,numberSum;
        mpz_init (number);
        mpz_init_set_str (numberSum,"0",10);        //initiating and setting variable "numberSum" to 0
        string line;

        while (getline(file,line))                  //while it is able to get a line from the file, do:
        {
            mpz_set_str(number,line.c_str(),10);    //setting var "number" to converted to char value of variable "line"
            mpz_add(numberSum,numberSum,number);    //numberSum=numberSum+number;
        }
        cout << numberSum << '\n';
        mpz_clear(number);
    }
    else
    {
        cout << "Error: Failed to open the file";
    }
    return 0;
}
