#include "ExpensesFileXml.h"

int ExpensesFileXml::getLastItemId()
{
    return lastItemId;
}

void ExpensesFileXml::setLastItemId(int newLastItemId)
{
    lastItemId = newLastItemId;
}

void ExpensesFileXml::addExpenseToFileXml(Expense expense)
{
    bool fileExists = xml.Load(getNameFile());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expense");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ItemId", HelperMethods::conversionIntToString(expense.getItemId()));
    xml.AddElem("UserId", HelperMethods::conversionIntToString(expense.getUserId()));
    xml.AddElem("Date", HelperMethods::putDashesInDate(HelperMethods::conversionIntToString(expense.getDate())));
    xml.AddElem("Category", expense.getCategory());
    xml.AddElem("Amount", HelperMethods::conversionFloatToString(expense.getAmount()));
    xml.Save(getNameFile());
}

 vector <Expense> ExpensesFileXml::loadExpensesLoggedUserFromFileXml(int idLoggedUser)
 {
    Expense expense;
    vector <Expense> expenses;

    bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    MCD_STR buffor;
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        expense = getDataExpense();
        if (expense.getUserId() == idLoggedUser)
        {
            expenses.push_back(expense);
        }
        xml.ResetMainPos();
        xml.FindElem("ItemId");
        buffor = xml.GetData();
        xml.OutOfElem();
    }

    lastItemId = atoi(buffor.c_str());

    xml.OutOfElem();
    xml.Save(getNameFile());


    return expenses;
 }
 
 Expense ExpensesFileXml::getDataExpense()
{
    Expense expense;
    MCD_STR itemId, userId, date, category, amount;

    xml.IntoElem();
    xml.FindElem("ItemId");
    itemId = xml.GetData();
    expense.setItemId(atoi(itemId.c_str()));

    xml.FindElem("UserId");
    userId = xml.GetData();
    expense.setUserId(atoi(userId.c_str()));

    xml.FindElem("Date");
    date = xml.GetData();
    date = HelperMethods::removeDashFromDate(date);
    expense.setDate(atoi(date.c_str()));

    xml.FindElem("Category");
    category = xml.GetData();
    expense.setCategory(category);

    xml.FindElem("Amount");
    amount = xml.GetData();
    amount = HelperMethods::checkAmount(amount);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}