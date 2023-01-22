#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <map>
#include <windows.h>
#include <cstdlib>

#include "Income.h"
#include "IncomesFileXml.h"
#include "ExpensesFileXml.h"
#include "DateManager.h"

using namespace std;

class FinanceManager {
    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    IncomesFileXml incomesFileXml;
    ExpensesFileXml expensesFileXml;

    Income giveDetailsNewIncome();
    Expense giveDetailsNewExpense();

    void headerIncomes();
    void headerExpenses();
    float writeOutExpenses(int i, float sumAmountExpenses);
    float writeOutIncomes(int i, float sumAmountIncomes);
    float seeChoosenLinesFromIcomes(char choice, int dateFrom,int dateTill);
    float seeChoosenLinesFromExpenses(char choice, int dateFrom,int dateTill);
    void sortIncomesAndExpenses();
    
public:
    FinanceManager(string nameIncomesFileXml,string nameExpensesFileXml, int idLoggedUser)
        : ID_LOGGED_USER(idLoggedUser), incomesFileXml(nameIncomesFileXml), expensesFileXml(nameExpensesFileXml) {
        incomes = incomesFileXml.loadIncomesLoggedUserFromFileXml(ID_LOGGED_USER);
        expenses = expensesFileXml.loadExpensesLoggedUserFromFileXml(ID_LOGGED_USER);
    };

    void addNewIncome();
    void addNewExpense();
    void seeBalance(char choice);
};
#endif
