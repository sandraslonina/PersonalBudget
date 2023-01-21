#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "Income.h"
#include "IncomesFileXml.h"
#include "ExpensesFileXml.h"
#include "DateManager.h"

#include <string>
#include <map>
#include <windows.h>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <vector>
#include <iostream>


using namespace std;

class FinanceManager
{
	
	const int ID_LOGGED_USER;
	
    vector <Income> incomes;
    vector <Expense> expenses;
    
    IncomesFileXml incomesFileXml;
    ExpensesFileXml expensesFileXml;
    
	Income giveDetailsNewIncome();
	Expense giveDetailsNewExpense();
	
	void  sortIncomesAndExpenses();
	void headerIncomes();
	void headerExpenses();
	float seeChoosenLinesFromIcomes(char choice, int startDate,int endDate);
	float seeChoosenLinesFromExpenses(char choice, int startDate,int endDate);
	float listOfIncomes (int i, float sumAmountIncomes);
	float listOfExpenses(int i, float sumAmountExpenses);
	
public:
	FinanceManager (string nameIncomesFileXml, string nameExpensesFileXml, int idLoggedUser)
	: ID_LOGGED_USER(idLoggedUser), incomesFileXml(nameIncomesFileXml), expensesFileXml(nameExpensesFileXml)
	{
		idLoggedUser = 0;
		incomes = incomesFileXml.loadIncomesLoggedUserFromFileXml(ID_LOGGED_USER);
		expenses = expensesFileXml.loadExpensesLoggedUserFromFileXml(ID_LOGGED_USER);
	};
    
    void addNewIncome();
    void addNewExpense();
void seeBalance(char choice);
    
    

	
	
	
};