#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
PersonalBudget personalBudget("Users.xml");

    char choice;

    while (true) {
        if (!personalBudget.userIsLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userSignUp();
                break;

            case '2':
                personalBudget.userSignIn();
                break;

            case '9':
                exit(0);
                break;

            default:
                cout << endl << "This option isn`t available in main menu." << endl << endl;
                system("pause");
                break;
            }

        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            
            case '7':
                personalBudget.changePasswordOfLoggedUser();
                break;

            case '8':
                personalBudget.userSignOut();
                break;
            }
        }
    }

    return 0;
}