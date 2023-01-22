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

class ExpensesFileXml: public FileXml
{
    CMarkup xml;
    
    int lastItemId;
    
    Expense getDataExpense();


 public:
    ExpensesFileXml(string nameExpensesFileXml): FileXml(nameExpensesFileXml){
        lastItemId = 0;
    };
   int getLastItemId();
   void setLastItemId(int newLastItemId);
   
   void addExpenseToFileXml(Expense expense);
   
   vector <Expense> loadExpensesLoggedUserFromFileXml(int idLoggedUser);
};


#endif
