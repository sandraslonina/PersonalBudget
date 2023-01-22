#include "FinanceManager.h"

void  FinanceManager:: sortIncomesAndExpenses()
{
    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
}

void FinanceManager::addNewIncome()
 {
    Income income;
    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    income = giveDetailsNewIncome();
    incomes.push_back(income);

     incomesFileXml.addIncomeToFileXml(income);

    cout << "Added new income!" << endl;
    system("pause");
    
    
}

Income FinanceManager::giveDetailsNewIncome()
{
    Income income;
    DateManager dateManager;
    income.setItemId(incomesFileXml.getLastItemId()+1);

    incomesFileXml.setLastItemId(income.getItemId());

    income.setUserId(ID_LOGGED_USER);

    income.setDate(dateManager.takeDateFromUser());

    string category;
    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    income.setCategory(category);

    string amount;
    cout << "Give an amount: ";
    cin >> amount;
    amount = HelperMethods::checkAmount(amount);
    income.setAmount(atof(amount.c_str()));

    return income;
}

void FinanceManager::addNewExpense()
{
    Expense expense;
    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    expense = giveDetailsNewExpense();
    expenses.push_back(expense);

    expensesFileXml.addExpenseToFileXml(expense);

    cout << "Added new expense!" << endl;
    system("pause");
}

Expense FinanceManager::giveDetailsNewExpense()
{
    Expense expense;
    DateManager dateManager;
    
    expense.setItemId(expensesFileXml.getLastItemId()+1);
    expensesFileXml.setLastItemId(expense.getItemId());

    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(dateManager.takeDateFromUser());

    string category;
    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    expense.setCategory(category);

    string amount;
    cout << "Give an amount: ";
    cin >> amount;
    amount = HelperMethods::checkAmount(amount);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}

void FinanceManager::headerIncomes()
{
    cout << "-------------------INCOMES-------------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "      DATE:       Category:              AMOUNT:   " << endl;
    cout << "---------------------------------------------------" << endl;
}
void FinanceManager::headerExpenses()
{
     cout << "-------------------EXPENSES-----------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "      DATE:       Category:              AMOUNT:   " << endl;
    cout << "---------------------------------------------------" << endl;
}

float FinanceManager::writeOutExpenses(int i, float sumAmountExpenses)
{
    DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(expenses[i].getDate())) << "    " << expenses[i].getCategory();
    string category = expenses[i].getCategory();
    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << expenses[i].getAmount()  << endl;
    sumAmountExpenses+= expenses[i].getAmount();
    return sumAmountExpenses;
}

float FinanceManager::writeOutIncomes(int i, float sumAmountIncomes)
{
    DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(incomes[i].getDate())) << "    " << incomes[i].getCategory();
    string category = incomes[i].getCategory();
    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << incomes[i].getAmount()  << endl;
    sumAmountIncomes+= incomes[i].getAmount();
    return sumAmountIncomes;
}

float FinanceManager::seeChoosenLinesFromIcomes(char choice, int dateFrom,int dateTill )
{
    float sumAmountIncomes = 0;
    for (unsigned int i = 0;  i < incomes.size(); i++)
    {
        if((incomes[i].getDate() >= dateFrom ) && (incomes[i].getDate() <= dateTill) )
        {
            sumAmountIncomes = writeOutIncomes(i,sumAmountIncomes);
        }
    }
    cout << endl << "               SUM INCOMES:" << sumAmountIncomes << endl << endl;
    return sumAmountIncomes;
}

float FinanceManager::seeChoosenLinesFromExpenses(char choice, int dateFrom,int dateTill )
{
    float sumAmountExpenses = 0;
    for (unsigned int i = 0;  i < expenses.size(); i++)
    {
        if((expenses[i].getDate() >= dateFrom ) && (expenses[i].getDate() <= dateTill) )
        {
            sumAmountExpenses = writeOutExpenses(i,sumAmountExpenses);
        }
    }
    cout << endl << "               SUM EXPENSES:" << sumAmountExpenses << endl << endl;
    return sumAmountExpenses;
}

void FinanceManager::seeBalance(char choice)
{
    system("cls");
    DateManager dateManager;
    sortIncomesAndExpenses();
    int dateFrom = dateManager.setStartDate(choice);
    int dateTill = dateManager.setEndDate(choice);
    system("cls");

    headerIncomes();
    float sumIncomes = seeChoosenLinesFromIcomes(choice, dateFrom, dateTill);

    headerExpenses();
    float sumExpenses = seeChoosenLinesFromExpenses(choice, dateFrom, dateTill);

    cout << "BALANCE: " << sumIncomes << " - " << sumExpenses << " = " << sumIncomes - sumExpenses << endl;

    system("pause");
}
