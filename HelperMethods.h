#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class HelperMethods
{
public:
    static string conversionIntToString(int  figure);
    static int conversionStringToInt(string number);
     static string conversionFloatToString(float number);
    
     static string getTheLine();
    static char getCharacter();
   
    
    static string putDashesInDate(string dateWithoutDashes);
    static string removeDashFromDate(string dateToCheck);
    static string checkAmount(string floatNumber);
};
#endif
