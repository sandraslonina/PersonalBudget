#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>

#include "Item.h"
#include "UserManager.h"

using namespace std;

class Income: public Item
{


public:
    Income(int itemId = 0, int userId = 0, int date = 0, string category = "",  float amount = 0)
    :Item (itemId, userId, date, category, amount)
    {};
};
#endif
