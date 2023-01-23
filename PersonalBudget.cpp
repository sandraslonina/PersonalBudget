#include "PersonalBudget.h"

bool PersonalBudget::userIsLoggedIn() {
    return userManager.userIsLoggedIn();
}

void PersonalBudget::userSignUp() {
    userManager.userSignUp();
}

void PersonalBudget::writeOutAllUsers() {
    userManager.writeOutAllUsers();
}

void PersonalBudget::userSignIn () {
    userManager.userSignIn();
    if (userManager.userIsLoggedIn())
	{
		financeManager = new FinanceManager(NAME_INCOMES_FILE_XML, NAME_EXPENSES_FILE_XML, userManager.getLoggedUserId());
	}
}

void PersonalBudget::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}

void PersonalBudget::userSignOut() {
    userManager.userSignOut();
}

void PersonalBudget::addNewIncome()
{
    if (userManager.userIsLoggedIn())
    {
        financeManager->addNewIncome();
    }
    else
    {
        cout << "Sorry, you must be logged in to add income!" << endl;
        system("pause");
    }
}

void PersonalBudget::addNewExpense()
{
    if (userManager.userIsLoggedIn())
    {
        financeManager -> addNewExpense();
    }
    else
    {
        cout << "Sorry, you must be logged in to add expense!" << endl;
        system("pause");
    }
}

void PersonalBudget::balanceForCurrentMonth(char choice)
{
    financeManager -> seeBalance(choice);
}

void PersonalBudget::balanceForLastMonth(char choice)
{
    financeManager -> seeBalance(choice);
}

void PersonalBudget::balanceForSelectedPeriod(char choice)
{
    financeManager -> seeBalance(choice);
}


char PersonalBudget::selectOptionFromMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "3. End" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::getCharacter();

    return choice;
}

char PersonalBudget::selectOptionFromUserMenu() {
    char choice;
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Sign out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::getCharacter();

    return choice;
}

