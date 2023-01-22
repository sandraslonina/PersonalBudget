#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <map>
#include <windows.h>
#include <cstdlib>

#include "HelperMethods.h"

class DateManager {
    int getCurrentDateOfSystem();
    string checkingPositionDashesInDate(string dateToCheck);
    bool checkIfDateHasDigits(string dateToCheck);

    int getYearFromDate(string dateToCheck);
    int getMonthFromDate(string dateToCheck);
    int getDayFromDate(string dateToCheck);

    int returnNumberDaysFromDate(string dateToCheck);
    string removeDashFromDate(string dateToCheck);
    string getDate();
    string getNameOfMonth(string dateToCheck);
    bool isDateCorrect(string dateToCheck);

public:
    int takeDateFromUser();
    int setStartDate(char choice);
    int setEndDate(char choice);

    string putDashesToDate(string date);
};
#endif