#include <iostream>
#include <iomanip>
using namespace std;

// Leap Year Function (checks if the year is a leap year)
bool isleapyear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return true;
    return false;
}

// Days in Month Function (returns the number of days in a given month and year)
int daysinmonth(int month, int year)
{
    switch(month)
    {
        case 1: return 31; // January
        case 2: return isleapyear(year) ? 29 : 28; // February
        case 3: return 31; // March
        case 4: return 30; // April
        case 5: return 31; // May
        case 6: return 30; // June
        case 7: return 31; // July
        case 8: return 31; // August
        case 9: return 30; // September
        case 10: return 31; // October
        case 11: return 30; // November
        case 12: return 31; // December
    }
    return 30;
}

// Counting method for first weekday of year
//0=Monday, 1=Tuesday, ..., 6=Sunday
int firstdayofyear(int year)
{
    int days = 0;
    for (int i = 1900; i < year; i++)
    {
        days += isleapyear(i) ? 366 : 365;
    }
    return days % 7;
}

string monthname(int month)
{
    switch(month)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
    return "";
}

int main()
{
    int year;
    cout << "Enter a year (1900 - 2450): ";
    cin >> year;

    if (year < 1900 || year > 2450)
    {
        cout << "Invalid year. Please enter a year between 1900 and 2450.\n";
        return 0;
    }
    int startday = firstdayofyear(year);
    cout << "Calendar for the year " << year << ":" << "\n";
    for (int month = 1; month <= 12; month++)
    {
        cout << "\n" << monthname(month) << " " << year << "--\n";
        cout << "Mon Tue Wed Thu Fri Sat Sun\n";

        int days = daysinmonth(month, year);
        
        // print leading spaces for the first day of the month
        for (int i = 0; i < startday; i++)
        {
            cout << setw(4) << " ";
        
            //print the days of the month
            for (int day = 1; day <= days; day++)
            startday++;

            if(startday == 7)
            {
                cout << endl;
                startday = 0;
            }
    }
    if(startday != 0)
    cout << endl;
}
return 0;
}