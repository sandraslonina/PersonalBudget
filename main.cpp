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

            case '8':
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
				personalBudget.addIncome();
				break;
				
			case '2':
			personalBudget.addExpense();
			break;
			
			case '3':
				personalBudget.balanceForCurrentMonth();
				break;
				
			case 4:
				personalBudget.balanceForLastMonth();
				break;
				
			case 5:
				personalBudget.balanceForSelectedPeriod();
				break;
				
            case '6':
                personalBudget.changePasswordOfLoggedUser();
                break;

            case '7':
                personalBudget.userSignOut();
                break;
            }
        }
    }

    return 0;
}