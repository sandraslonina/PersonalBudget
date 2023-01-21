#ifndef EXPENSESFILEXML_H
#define EXPENSESFILEXML_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "Expense.h"
#include "HelperMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class ExpensesFileXml : public FileXml
{
	CMarkup xml;
	
	Expense getDataExpense();
	
	int lastItemId;
	
public:
    ExpensesFileXml(string nameExpensesFileXml) : FileXml(nameExpensesFileXml) 
    {
    	lastItemId = 0;
    };
    int getLastItemId();
    void setLastItemId(int newLastItemId);
    
     vector <Expense> loadExpensesLoggedUserFromFileXml(int idLoggedUser);
     
     void addExpenseToFileXml(Expense expense);
     
};
#endif