#include "DateManager.h"

int DateManager::takeDateFromUser() {
    char choice;
    string dateToCheck;

    cout << "Do you want to add item with current date?" << endl << endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = HelperMethods::getCharacter();

    if (choice == 'y') {
        return getCurrentDateOfSystem();

    } else if  (choice == 'n') {
        do {
            cout << "Enter the date your item in format YYYY-MM-DD: ";
            dateToCheck = HelperMethods::getTheLine();
            dateToCheck = checkingPositionDashesInDate(dateToCheck);
        } while (isDateCorrect(dateToCheck) != true);

        return HelperMethods::conversionStringToInt(removeDashFromDate(dateToCheck));
    }

    return 0;
}

int DateManager::getCurrentDateOfSystem() {
    string year, month, day;

    time_t t = time(0);
    struct tm * now = localtime( & t );
    year = HelperMethods::conversionIntToString(now->tm_year + 1900);
    month = HelperMethods::conversionIntToString(now->tm_mon + 1);
    day = HelperMethods::conversionIntToString(now->tm_mday);

    if ( month.size() == 1)
        month = "0" + month;

    if ( day.size() == 1)
        day = "0" + day;

    return HelperMethods::conversionStringToInt(year + month + day);
}

string DateManager::checkingPositionDashesInDate(string dateToCheck) {
    int longOfDate = dateToCheck.length();

    if (longOfDate == 10) {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45)
            return dateToCheck;

    } else if (longOfDate == 9 ) {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45) {
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;

        } else if ( dateToCheck[4] == 45 && dateToCheck[6] == 45) {
            dateToCheck = dateToCheck.insert(5,"0");
            return dateToCheck;
        }

    } else if (longOfDate == 8 ) {
        if ( dateToCheck[4] == 45 && dateToCheck[6] == 45) {
            dateToCheck = dateToCheck.insert(5,"0");
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;
        }
    }

    return 0;
}

bool DateManager::checkIfDateHasDigits(string dateToCheck) {
    for (unsigned int i = 0; i < dateToCheck.length(); i++) {
        if (dateToCheck[i] > 57) {
            i =  dateToCheck.length();
            return true;
        }
    }

    return 0;
}

int DateManager::getYearFromDate(string dateToCheck) {
    int year = HelperMethods::conversionStringToInt(dateToCheck.erase(4,4));

    if (year < 2000 )
        return 0;

    return year;
}

int DateManager::getMonthFromDate(string dateToCheck) {
    int month;
    dateToCheck = dateToCheck.erase(0,4);
    month = HelperMethods::conversionStringToInt(dateToCheck.erase(2,2));

    if (month > 12 )
        return 0;

    else
        return month;
}

int DateManager::getDayFromDate(string dateToCheck) {
    int day;
    day = HelperMethods::conversionStringToInt(dateToCheck.erase(0,6));

    if (day > 31 )
        return 0;

    else
        return day;
}

int DateManager::returnNumberDaysFromDate(string dateToCheck) {
    switch(getMonthFromDate(dateToCheck)) {
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

    case 2: {
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

int DateManager::setStartDate(char choice) {
    string date = HelperMethods::conversionIntToString(getCurrentDateOfSystem());

    if( choice == '3') {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date));

        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;

        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + "01";
        return HelperMethods::conversionStringToInt(date);

    } else if( choice == '4') {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date)-1);

        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;

        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + "01";
        return HelperMethods::conversionStringToInt(date);

    } else if( choice == '5') {
        cout << "Start date of balance(YYYY-MM-DD) " << endl;
        string date = getDate();
        return HelperMethods::conversionStringToInt(removeDashFromDate(date));
    }

    return 0;
}

int DateManager::setEndDate(char choice) {
    string date = HelperMethods::conversionIntToString(getCurrentDateOfSystem());

    if( choice == '3') {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date));

        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;

        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + HelperMethods::conversionIntToString(returnNumberDaysFromDate(date));
        return HelperMethods::conversionStringToInt(date);

    } else if( choice == '4') {
        string stringMonth = HelperMethods::conversionIntToString(getMonthFromDate(date)-1);

        if ( stringMonth.size() == 1)
            stringMonth = "0" + stringMonth;

        date = HelperMethods::conversionIntToString(getYearFromDate(date)) + stringMonth + HelperMethods::conversionIntToString(returnNumberDaysFromDate(date));
        return HelperMethods::conversionStringToInt(date);

    } else if( choice == '5') {
        cout <<  "Finish date of balance(YYYY-MM-DD) " << endl;
        string date = getDate();
        return HelperMethods::conversionStringToInt(removeDashFromDate(date));
    }

    return 0;
}

string DateManager::removeDashFromDate(string dateToCheck) {
    string dateWithoutDash;
    dateWithoutDash = dateToCheck.erase(4,1);
    dateWithoutDash = dateToCheck.erase(6,1);

    return dateWithoutDash;
}

string DateManager::getDate() {
    string date = "";

    do {
        do {
            cout << "Enter date: ";
            date = HelperMethods::getTheLine();
        } while (date == "");

        date = checkingPositionDashesInDate(date);
    } while ((isDateCorrect(date) != true));

    return date;
}

string  DateManager::putDashesToDate(string date) {
    date = date.insert(4,"-");
    date = date.insert(7,"-");

    return date;
}

string DateManager::getNameOfMonth(string dateToCheck) {
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

bool DateManager::isDateCorrect(string dateToCheck) {
    dateToCheck = removeDashFromDate(dateToCheck);

    if(checkIfDateHasDigits(dateToCheck)) {
        cout << "Please type date with correct format: YYYY-MM-DD"  << endl;
        return false;

    } else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) == 0) {
        cout << "Month must be between 1 and 12. Please enter correct month"  << endl;
        cout << "Day must be between 1 and 31. Please enter correct month"  << endl;
        return false;

    } else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) != 0) {
        cout << "Month must be between 1 and 12. Please enter correct month"  << endl;
        return false;

    } else if (getMonthFromDate(dateToCheck) != 0 && getDayFromDate(dateToCheck) == 0) {
        cout << "Day must be between 1 and 31. Please enter correct month"  << endl;
        return false;

    } else if (returnNumberDaysFromDate(dateToCheck) < getDayFromDate(dateToCheck)) {
        cout << getNameOfMonth(dateToCheck) <<" doesn't have, so many days "<< endl;
        return false;

    } else if (getYearFromDate(dateToCheck) == 0) {
        cout << "Put year more than 2000 "  << endl;
        return false;

    } else
        return true;
}