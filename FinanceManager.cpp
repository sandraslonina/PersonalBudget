#include "FinanceManager.h"

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

   string category, amount; 
    
    income.setItemId(incomesFileXml.getLastItemId()+1);
    incomesFileXml.setLastItemId(income.getItemId());
    income.setUserId(ID_LOGGED_USER);
    income.setDate(dateManager.takeDateFromUser());
    
    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    income.setCategory(category);

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
    
    string category, amount; 
    
    expense.setItemId(expensesFileXml.getLastItemId()+1);
    expensesFileXml.setLastItemId(expense.getItemId());
    expense.setUserId(ID_LOGGED_USER);
    expense.setDate(dateManager.takeDateFromUser());

    cout << "Give a category: " ;
    category = HelperMethods::getTheLine();
    expense.setCategory(category);

    cout << "Give an amount: ";
    cin >> amount;
    amount = HelperMethods::checkAmount(amount);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}


void FinanceManager::seeBalance(char choice)
{
    int startDate, endDate;
    float sumIncomes, sumExpenses;
    
    system("cls");
    
    DateManager dateManager;
    
    sortIncomesAndExpenses();
    
    startDate = dateManager.setStartDate(choice);
    endDate = dateManager.setEndDate(choice);
    
    system("cls");

    headerIncomes();
    sumIncomes = seeChoosenLinesFromIcomes(choice, startDate, endDate);

    headerExpenses();
    sumExpenses = seeChoosenLinesFromExpenses(choice, startDate, endDate);

    cout << "BALANCE: " << sumIncomes << " - " << sumExpenses << " = " << sumIncomes - sumExpenses << endl;

    system("pause");
}

void  FinanceManager:: sortIncomesAndExpenses()
{
    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

}

void FinanceManager::headerIncomes()
{
    cout << "***************************************************" << endl;
    cout << "*                  INCOMES                        *" << endl;
    cout << "***************************************************" << endl;
    cout << "*     DATE    *    Category           *  AMOUNT   *" << endl;
    cout << "***************************************************" << endl;
}

void FinanceManager::headerExpenses()
{
    cout << "***************************************************" << endl;
    cout << "*                 EXPENSES                        *" << endl;
    cout << "***************************************************" << endl;
    cout << "*     DATE    *    Category           *  AMOUNT   *" << endl;
    cout << "***************************************************" << endl;
}


float FinanceManager::seeChoosenLinesFromIcomes(char choice, int startDate,int endDate)
{
    float sumAmountIncomes = 0;
    for (unsigned int i = 0;  i < incomes.size(); i++)
    {
        if((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate))
        {
            sumAmountIncomes = listOfIncomes(i,sumAmountIncomes);
        }
    }
    cout << endl << "               SUM INCOMES:" << sumAmountIncomes << endl << endl;
    return sumAmountIncomes;
}

float FinanceManager::seeChoosenLinesFromExpenses(char choice, int startDate,int endDate)
{
    float sumAmountExpenses = 0;
    for (unsigned int i = 0;  i < expenses.size(); i++)
    {
        if((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <= endDate))
        {
            sumAmountExpenses = listOfIncomes(i,sumAmountExpenses);
        }
    }
    cout << endl << "               SUM EXPENSES:" << sumAmountExpenses << endl << endl;
    return sumAmountExpenses;
}

float FinanceManager::listOfIncomes (int i, float sumAmountIncomes)
{
    DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(incomes[i].getDate())) << "    " << incomes[i].getCategory();
    string category = incomes[i].getCategory();
    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << incomes[i].getAmount()  << endl;
    sumAmountIncomes += incomes[i].getAmount();
    return sumAmountIncomes;
}

float FinanceManager::listOfExpenses(int i, float sumAmountExpenses)
{
    DateManager dateManager;
    cout << " " << dateManager.putDashesToDate(HelperMethods::conversionIntToString(expenses[i].getDate())) << "    " << expenses[i].getCategory();
    string category = expenses[i].getCategory();
    for (unsigned int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << expenses[i].getAmount()  << endl;
    sumAmountExpenses += expenses[i].getAmount();
    return sumAmountExpenses;
}