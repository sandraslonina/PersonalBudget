#include "HelperMethods.h" 

string HelperMethods::conversionIntToString(int figure)
{
    ostringstream ss;
    ss << figure;
    string str = ss.str();
    return str;
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