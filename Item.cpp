#include "Item.h"

bool Item::operator < (const Item& str) const {
    return (this->date < str.date);
}

void Item::setItemId(int newItemId) {
    if(newItemId >= 0)
        itemId = newItemId;
}

void Item::setUserId(int newUserId) {
    if(newUserId >= 0)
        userId = newUserId;
}

void Item::setDate(int newDate) {
    date = newDate;
}

void Item::setCategory(string newCategory) {
    category = newCategory;
}

void Item::setAmount(float newAmount) {
    amount = newAmount;
}

int Item::getItemId() {
    return itemId;
}

int Item::getUserId() {
    return userId;
}

int Item::getDate() {
    return date;
}

string Item::getCategory() {
    return category;
}

float Item::getAmount() {
    return amount;
}
