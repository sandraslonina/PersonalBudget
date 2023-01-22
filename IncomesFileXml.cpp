#include "IncomesFileXml.h"

int IncomesFileXml::getLastItemId() {
    return lastItemId;
}

void IncomesFileXml::setLastItemId(int newLastItemId) {
    lastItemId = newLastItemId;
}

void IncomesFileXml::addIncomeToFileXml(Income income) {
    bool fileExists = xml.Load(getNameFile());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("ItemId", HelperMethods::conversionIntToString(income.getItemId()));
    xml.AddElem("UserId", HelperMethods::conversionIntToString(income.getUserId()));
    xml.AddElem("Date", HelperMethods::putDashesInDate(HelperMethods::conversionIntToString(income.getDate())));
    xml.AddElem("Category", income.getCategory());
    xml.AddElem("Amount", HelperMethods::conversionFloatToString(income.getAmount()));
    xml.Save(getNameFile());
}

vector <Income> IncomesFileXml::loadIncomesLoggedUserFromFileXml(int idLoggedUser) {
    Income income;
    vector <Income> incomes;

    bool fileExists = xml.Load(getNameFile());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    MCD_STR buffor;
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {
        income = giveDataNewIncome();

        if (income.getUserId() == idLoggedUser) {
            incomes.push_back(income);
        }

        xml.ResetMainPos();
        xml.FindElem("ItemId");
        buffor = xml.GetData();
        xml.OutOfElem();
    }

    lastItemId = atoi(buffor.c_str());

    xml.OutOfElem();
    xml.Save(getNameFile());

    return incomes;
}

Income IncomesFileXml::giveDataNewIncome() {
    Income income;
    MCD_STR itemId, userId, date, category, amount;

    xml.IntoElem();
    xml.FindElem("ItemId");
    itemId = xml.GetData();
    income.setItemId(atoi(itemId.c_str()));

    xml.FindElem("UserId");
    userId = xml.GetData();
    income.setUserId(atoi(userId.c_str()));

    xml.FindElem("Date");
    date = xml.GetData();
    date = HelperMethods::removeDashFromDate(date);
    income.setDate(atoi(date.c_str()));

    xml.FindElem("Category");
    category = xml.GetData();
    income.setCategory(category);

    xml.FindElem("Amount");
    amount = xml.GetData();
    amount = HelperMethods::checkAmount(amount);
    income.setAmount(atof(amount.c_str()));

    return income;
}