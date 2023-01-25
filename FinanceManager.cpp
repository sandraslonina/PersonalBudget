#include "FinanceManager.h"

void FinanceManager::addNewIncome() {
    Income income;
    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    income = giveDetailsNewIncome();
    incomes.push_back(income);

    incomesFileXml.addIncomeToFileXml(income);

    cout << "Added new income!" << endl;
    system("pause");
}

void FinanceManager::addNewExpense() {
    Expense expense;
    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    expense = giveDetailsNewExpense();
    expenses.push_back(expense);

    expensesFileXml.addExpenseToFileXml(expense);

    cout << "Added new expense!" << endl;
    system("pause");
}

Income FinanceManager::giveDetailsNewIncome() {
    string category;
    float amount;

    Income income;

    income.setItemId(incomesFileXml.getLastItemId()+1);
    incomesFileXml.setLastItemId(income.getItemId());

    income.setUserId(ID_LOGGED_USER);

    income.setDate(dateManager.takeDateFromUser());

    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    income.setCategory(category);

    cout << "Give an amount (e.g. 10.50): ";
    amount = HelperMethods::getFloat();
    income.setAmount(amount);

    return income;
}

Expense FinanceManager::giveDetailsNewExpense() {
    string category;
    float amount;

    Expense expense;

    expense.setItemId(expensesFileXml.getLastItemId()+1);
    expensesFileXml.setLastItemId(expense.getItemId());

    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(dateManager.takeDateFromUser());

    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    expense.setCategory(category);

    cout << "Give an amount (e.g. 10.50): ";
    amount = HelperMethods::getFloat();
    expense.setAmount(amount);

    return expense;
}

void FinanceManager::headerIncomes() {
    cout << "-------------------INCOMES-------------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "      DATE:       Category:              AMOUNT:   " << endl;
    cout << "---------------------------------------------------" << endl;
}
void FinanceManager::headerExpenses() {
    cout << "-------------------EXPENSES------------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "      DATE:       Category:              AMOUNT:   " << endl;
    cout << "---------------------------------------------------" << endl;
}

float FinanceManager::writeOutIncomes(int i, float sumAmountIncomes) {
    //DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(incomes[i].getDate())) << "    " << incomes[i].getCategory();
    string category = incomes[i].getCategory();

    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";

    cout << fixed << setprecision(2) << incomes[i].getAmount()  << endl;
    sumAmountIncomes+= incomes[i].getAmount();
    return sumAmountIncomes;
}

float FinanceManager::writeOutExpenses(int i, float sumAmountExpenses) {
    //DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(expenses[i].getDate())) << "    " << expenses[i].getCategory();
    string category = expenses[i].getCategory();

    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";

    cout << fixed << setprecision(2) << expenses[i].getAmount()  << endl;
    sumAmountExpenses += expenses[i].getAmount();
    return sumAmountExpenses;
}

float FinanceManager::seeChoosenLinesFromIcomes(char choice, int dateFrom,int dateTill ) {
    float sumAmountIncomes = 0.00;

    for (unsigned int i = 0;  i < incomes.size(); i++) {
        if((incomes[i].getDate() >= dateFrom ) && (incomes[i].getDate() <= dateTill) ) {
            sumAmountIncomes = writeOutIncomes(i,sumAmountIncomes);
        }
    }

    cout << endl << "               SUM INCOMES: " << fixed << setprecision(2) << sumAmountIncomes << " PLN" << endl << endl;
    return sumAmountIncomes;
}

float FinanceManager::seeChoosenLinesFromExpenses(char choice, int dateFrom,int dateTill ) {
    float sumAmountExpenses = 0.00;

    for (unsigned int i = 0;  i < expenses.size(); i++) {
        if((expenses[i].getDate() >= dateFrom ) && (expenses[i].getDate() <= dateTill) ) {
            sumAmountExpenses = writeOutExpenses(i,sumAmountExpenses);
        }
    }

    cout << endl << "               SUM EXPENSES: " << fixed << setprecision(2) << sumAmountExpenses << " PLN" << endl << endl;
    return sumAmountExpenses;
}

void FinanceManager::seeBalance(char choice) {
    int dateFrom, dateTill;
    float sumIncomes, sumExpenses;

    system("cls");

    sortIncomesAndExpenses();

    dateFrom = dateManager.setStartDate(choice);
    dateTill = dateManager.setEndDate(choice);
    system("cls");

    headerIncomes();
    sumIncomes = seeChoosenLinesFromIcomes(choice, dateFrom, dateTill);

    headerExpenses();
    sumExpenses = seeChoosenLinesFromExpenses(choice, dateFrom, dateTill);

    cout << "BALANCE: " << sumIncomes << " - " << sumExpenses << " = " << sumIncomes - sumExpenses << " PLN" << endl;

    system("pause");
}

void  FinanceManager:: sortIncomesAndExpenses() {
    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
}
