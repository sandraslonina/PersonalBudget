#include "DateManager.h"

int DateManager::getCurrentDateOfSystem()
{
    time_t t = time(0);   
    struct tm * now = localtime( & t );
    string year = HelperMethods::conversionIntToString(now->tm_year + 1900);
    string month = HelperMethods::conversionIntToString(now->tm_mon + 1);
    string day = HelperMethods::conversionIntToString(now->tm_mday);

    if ( month.size() == 1)
        month = "0" + month;

    if ( day.size() == 1)
        day = "0" + day;

    return HelperMethods::conversionStringToInt(year + month + day);
}

int DateManager::takeDateFromUser()
{
    char sign;
    string dateToCheck;

    cout << "Choose option dates: "<< endl;
    cout << "1. Take date from today  " << endl;
    cout << "2. Take date from other day (exp: 2019-08-01)  " << endl;
    sign = HelperMethods::getCharacter();
    if (sign == '1')
    {
       return getCurrentDateOfSystem();
    }
    else if  (sign == '2')
    {
        do
        {
            cout << "Put date(exp: 2019-08-01): ";
            dateToCheck = HelperMethods::getTheLine();
            dateToCheck = checkingPositionDashesInDate(dateToCheck);
        }
        while (isDateCorrect(dateToCheck) != true);
        return HelperMethods::conversionStringToInt(removeDashFromDate(dateToCheck));
    }
}

string DateManager::removeDashFromDate(string dateToCheck)
{
    string dateWithoutDash;
    dateWithoutDash = dateToCheck.erase(4,1);
    dateWithoutDash = dateToCheck.erase(6,1);

    return dateWithoutDash;
}

string DateManager::checkingPositionDashesInDate(string dateToCheck)
{
    int longOfDate = dateToCheck.length();
    if (longOfDate == 10)
    {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45)
            return dateToCheck;
    }
    else if (longOfDate == 9 )
    {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45)
        {
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;
        }
        else if ( dateToCheck[4] == 45 && dateToCheck[6] == 45)
        {
            dateToCheck = dateToCheck.insert(5,"0");
            return dateToCheck;
        }
    }
    else if (longOfDate == 8 )
    {
        if ( dateToCheck[4] == 45 && dateToCheck[6] == 45)
        {
            dateToCheck = dateToCheck.insert(5,"0");
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;
        }
    }
}

bool DateManager::checkIfDateHasDigits(string dateToCheck)
{
    for (unsigned int i = 0; i < dateToCheck.length(); i++)
    {
        if (dateToCheck[i] > 57)
        {
            i =  dateToCheck.length();
            return true;
        }
    }
}

int DateManager::getYearFromDate(string dateToCheck)
{
    int year = HelperMethods::conversionStringToInt(dateToCheck.erase(4,4));
    if (year < 2000 )
        return 0;
    return year;
}

int DateManager::getMonthFromDate(string dateToCheck)
{
    int month;
    dateToCheck = dateToCheck.erase(0,4);
    month = HelperMethods::conversionStringToInt(dateToCheck.erase(2,2));
     if (month > 12 )
        return 0;
    else
        return month;
}

int DateManager::getDayFromDate(string dateToCheck)
{
    int day;
    day = HelperMethods::conversionStringToInt(dateToCheck.erase(0,6));
    if (day > 31 )
        return 0;
    else
        return day;
}

int DateManager::returnNumberDaysfromDate(string dateToCheck)
{
    switch(getMonthFromDate(dateToCheck))
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
    {
        if (((getYearFromDate(dateToCheck)%4 == 0) && (getYearFromDate(dateToCheck)%100 != 0)) || (getYearFromDate(dateToCheck)%400 == 0))
            return 29;
        else
            return 28;
    }
    break;

    default:
        return 0;
    }
}

int DateManager::setStartDate(char choice)
{
    string date = HelperMethods::conversionIntToString(getCurrentDateOfSystem());
    if( choice == '3')
    {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date));
        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;
        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + "01";
        return HelperMethods::conversionStringToInt(date);
    }
    else if( choice == '4')
    {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date)-1);
        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;
        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + "01";
        return HelperMethods::conversionStringToInt(date);
    }
    else if( choice == '5')
    {
        cout << "Start date of balance(exp: 2019-08-01) " << endl;
        string date = getDate();
        return HelperMethods::conversionStringToInt(removeDashFromDate(date));
    }
}

int DateManager::setEndDate(char choice)
{
    string date = HelperMethods::conversionIntToString(getCurrentDateOfSystem());
    if( choice == '3')
    {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date));
        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;
        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + HelperMethods::conversionIntToString(returnNumberDaysfromDate(date));
        return HelperMethods::conversionStringToInt(date);
    }
    else if( choice == '4')
    {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date)-1);
        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;
        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + HelperMethods::conversionIntToString(returnNumberDaysfromDate(date));
        return HelperMethods::conversionStringToInt(date);
    }
     else if( choice == '5')
    {
        cout <<  "Finish date of balance(exp: 2019-08-01) " << endl;
        string date = getDate();
        return HelperMethods::conversionStringToInt(removeDashFromDate(date));
    }
}

string DateManager::getDate()
{
    string date = "";
    do
    {
        do
        {
          cout << "Put date: ";
          date = HelperMethods::getTheLine();
        }while (date == "");
        date = checkingPositionDashesInDate(date);
    }
    while ((isDateCorrect(date) != true));
    return date;
}

string  DateManager::putDashesToDate(string date)
{
    date = date.insert(4,"-");
    date = date.insert(7,"-");

    return date;
}

string DateManager::getNameOfMonth(string dateToCheck)
{
    int monthFromDate = getMonthFromDate(dateToCheck);
    map<int,string> month;
    month[1] = "January";
    month[2] = "February";
    month[3] = "March";
    month[4] = "April";
    month[5] = "May";
    month[6] = "June";
    month[7] = "July";
    month[8] = "August";
    month[9] = "September";
    month[10] = "October";
    month[11] = "November";
    month[12] = "December";

    return month.find((int)monthFromDate) -> second;
}

bool DateManager::isDateCorrect(string dateToCheck)
{
    dateToCheck = removeDashFromDate(dateToCheck);
     if(checkIfDateHasDigits(dateToCheck))
    {
        cout << "Please type date with correct format: yyyy-mm-dd,exp 2019-01-02"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) == 0)
    {
        cout << "Month is not between 1 and 12, please put correct month"  << endl;
        cout << "Day is not between 1 and 31, please put correct day"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) != 0)
    {
         cout << "Month is not between 1 and 12, please put correct month"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) != 0 && getDayFromDate(dateToCheck) == 0)
    {
        cout << "Day is not between 1 and 31, please put correct day"  << endl;
        return false;
    }
    else if (returnNumberDaysfromDate(dateToCheck)< getDayFromDate(dateToCheck))
    {
        cout << getNameOfMonth(dateToCheck) <<" doesn't have, so many days "<< endl;
        return false;
    }
    else if (getYearFromDate(dateToCheck) == 0)
    {
         cout << "Put year more than 2000 "  << endl;
         return false;
    }
    else
        return true;
}
