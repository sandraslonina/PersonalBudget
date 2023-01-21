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
	
	Expense getDataIncome();
	
	int lastItemId;
	
public:
    IncomesFileXml(string nameIncomesFileXml) : FileXml(nameIncomesFileXml) 
    {
    	lastItemId = 0;
    };
    int getLastItemId();
    void setLastItemId(int newLastItemId);
    
     vector <Expense> loadExpensesLoggedUserFromFileXml();
     
     void addIncomeToFileXml(Item item);
     
};
#endif
	
	
	
	
	
	
};