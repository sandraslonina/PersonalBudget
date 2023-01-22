#include "HelperMethods.h"

string HelperMethods::conversionIntToString(int figure)
{
    ostringstream ss;
    ss << figure;
    string str = ss.str();
    return str;
}

int HelperMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string HelperMethods::conversionFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}



string HelperMethods::getTheLine()
{
    string input = "";
	cin.sync();
    getline(cin, input);
    return input;
}

char HelperMethods::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
    }
    return character;
}

string HelperMethods::removeDashFromDate(string dateToCheck)
{
    string dateWithoutDash;
    dateWithoutDash = dateToCheck.erase(4,1);
    dateWithoutDash = dateToCheck.erase(6,1);

    return dateWithoutDash;
}

string HelperMethods::putDashesInDate(string dateWithoutDashes)
{
    dateWithoutDashes.insert(4,"-");
    dateWithoutDashes.insert(7,"-");

    return dateWithoutDashes;
}


string HelperMethods::checkAmount(string floatNumber)
{
    for (unsigned int i = 0; i < floatNumber.length(); i++)
    {
        if (floatNumber[i] == 44)
        {
            floatNumber[i] = 46;
        }
    }
    return floatNumber;
}
