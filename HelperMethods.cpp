#include "HelperMethods.h" 

string HelperMethods::conversionIntToString(int figure)
{
    ostringstream ss;
    ss << figure;
    string str = ss.str();
    return str;
}

int HelperMethods::conversionStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}


string HelperMethods::getTheLine() {
    string input = "";
    cin.sync();
    getline (cin, input);
    return input;
}

char HelperMethods::getCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }

        cout << "This isn`t a single character. Enter again." << endl;
    }

    return character;
}

string HelperMethods::putDashesInDate(string dateWithoutDashes)
{
    dateWithoutDashes.insert(4,"-");
    dateWithoutDashes.insert(7,"-");

    return dateWithoutDashes;
}

string HelperMethods::conversionFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


string HelperMethods::checkAmount(string floatNumber)
{
    for (int i = 0; i < floatNumber.length(); i++)
    {
        if (floatNumber[i] == 44)
        {
            floatNumber[i] = 46;
        }
    }
    return floatNumber;
}

