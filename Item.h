#ifndef ITEM_H
#define ITEM_H

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Item {
    int itemId;
    int userId;
    int date;
    string category;
    float amount;

public:
    Item (int itemId = 0, int userId = 0, int date = 0, string category = "",  float amount = 0) {
        
        this -> itemId = itemId;
        this -> userId = userId;
        this -> date = date;
        this -> category = category;
        this -> amount = amount;
    }
    void setItemId(int newItemId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setCategory(string newCategory);
    void setAmount(float newAmount);


    int getItemId();
    int getUserId();
    int getDate();
    string getCategory();
    float getAmount();

    bool operator < (const Item& str) const;
};

#endif
