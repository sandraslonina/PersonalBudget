#ifndef INCOMESFILEXML_H
#define INCOMESFILEXML_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>

#include "Income.h"
#include "HelperMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class IncomesFileXml: public FileXml
{
    CMarkup xml;
    
    Income giveDataNewIncome();
    
    int lastItemId;

 public:
    IncomesFileXml(string nameIncomesFileXml): FileXml(nameIncomesFileXml){
        lastItemId = 0;
    };
    int getLastItemId();
    void setLastItemId(int newLastItemId);
    
    void addIncomeToFileXml(Income income);
    
    vector <Income> loadIncomesLoggedUserFromFileXml(int idLoggedUser);
};
#endif