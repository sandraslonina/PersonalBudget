#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"
#include "HelperMethods.h"

class PersonalBudget {
    UserManager userManager;
    FinanceManager *financeManager;

    const string NAME_INCOMES_FILE_XML;
    const string NAME_EXPENSES_FILE_XML;

public:
    PersonalBudget(string nameUsersFileXml, string nameIncomesFileXml, string nameExpensesFileXml) : userManager(nameUsersFileXml), NAME_INCOMES_FILE_XML(nameIncomesFileXml), NAME_EXPENSES_FILE_XML(nameExpensesFileXml) {
        financeManager = NULL;
    };
    ~PersonalBudget() {
        delete financeManager;
        financeManager = NULL;
    };

    bool userIsLoggedIn();

    void userSignUp();
    void writeOutAllUsers();
    void userSignIn();
    void changePasswordOfLoggedUser();
    void userSignOut();

    void addNewIncome();
    void addNewExpense();

    void balanceForCurrentMonth(char choice);
    void balanceForLastMonth(char choice);
    void balanceForSelectedPeriod(char choice);

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};
#endif