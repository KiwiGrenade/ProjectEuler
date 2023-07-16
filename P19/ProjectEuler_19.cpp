#include <iostream>
using namespace std;
int main()
{
    int monthsDayLimit=0,dayCounter=0,sundayCounter=0;
    string month;
    for (int year=1900; year<2000+1;year++)
    {
        int m=1;


        for ( m = 1; m<13; m++)
        {
            switch (m)
            {
                case 1: monthsDayLimit=31;month="January";break;
                case 2: if ((year%100==0 && year%400==0) || (year%4==0 && year%100!=0)){monthsDayLimit=29;month="February";break;}
                        else monthsDayLimit=28;month="February";break;
                case 3: monthsDayLimit=31,month="March";break;
                case 4: monthsDayLimit=30,month="April";break;
                case 5: monthsDayLimit=31,month="May";break;
                case 6: monthsDayLimit=30,month="June";break;
                case 7: monthsDayLimit=31,month="July";break;
                case 8: monthsDayLimit=31,month="August";break;
                case 9: monthsDayLimit=30,month="September";break;
                case 10: monthsDayLimit=31,month="October";break;
                case 11: monthsDayLimit=30,month="November";break;
                case 12: monthsDayLimit=31;month="December";break;
            }

            for (int d=1; d < (monthsDayLimit+1) ;d++)
            {
                dayCounter++;
                if (year > 1900 && dayCounter%7==0 && d==1)
                {
                    sundayCounter++;
                    cout  << "Year: " << year << "Month: " << month <<'/'<< monthsDayLimit << ' ' << "Day: " << d << '=' << "Sunday" << '\n';
                }
            }
        }
    }
    cout << sundayCounter;
    return 0;
}
