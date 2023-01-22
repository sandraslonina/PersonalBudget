#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

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

            case '3':
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

            case '1':
                personalBudget.addNewIncome();
                break;

            case '2':
                personalBudget.addNewExpense();
                break;

            case '3':
                personalBudget.balanceForCurrentMonth(choice);
                break;

            case '4':
                personalBudget.balanceForLastMonth(choice);
                break;

            case '5':
                personalBudget.balanceForSelectedPeriod(choice);
                break;

            case '6':
                personalBudget.changePasswordOfLoggedUser();
                break;

            case '7':
                personalBudget.userSignOut();
                break;

            default:
                cout << endl << "This option isn`t available in user menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
