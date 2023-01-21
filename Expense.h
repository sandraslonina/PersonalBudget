#ifndef EXPENSE_H
#define EXPENSE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <windows.h>

#include "Item.h"
#include "UserManager.h"

using namespace std;

class Expense: public Item
{


public:
    Expense(int itemId = 0, int userId = 0, int date = 0, string category = "",  float amount = 0)
    : Item (itemId, userId, date, category, amount)
    {};

};

#endif
