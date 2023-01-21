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

class IncomesFileXml : public FileXml
{
	CMarkup xml;
	
	Income getDataIncome();
	
	int lastItemId;
	
public:
    IncomesFileXml(string nameIncomesFileXml) : FileXml(nameIncomesFileXml) 
    {
    	lastItemId = 0;
    };
    int getLastItemId();
    void setLastItemId(int newLastItemId);
    
     vector <Income> loadIncomesLoggedUserFromFileXml(int idLoggedUser);
     
     void addIncomeToFileXml(Income income);
     
};
#endif
