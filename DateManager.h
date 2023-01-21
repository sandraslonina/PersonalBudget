#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <iostream>
#include <map>
#include <windows.h>
#include <cstdlib>

#include "HelperMethods.h"

class DateManager
{
public:

int getCurrentDateOfSystem();
char takeDateFromUser();
      string checkingPositionDashesInDate(string dateToCheck);
      bool isDateCorrect(string dateToCheck);
      string removeDashFromDate(string dateToCheck);
      bool checkIfDateHasDigits(string dateToCheck);
      int getYearFromDate(string dateToCheck);
      int getMonthFromDate(string dateToCheck);
      int getDayFromDate(string dateToCheck);
      int returnNumberDaysfromDate(string dateToCheck);
      string getNameOfMonth(string dateToCheck);
      int setStartDate(char choice);
      int setEndDate(char choice);
      string getDate();
      string putDashesToDate(string date);
};
#endif

