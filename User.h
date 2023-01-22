#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    User (int id = 0, string login = "", string password = "", string name = "", string surname = "") {
        this -> id = id;
        this -> login = login;
        this -> password = password;
        this -> name = name;
        this -> surname = surname;
    }
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};
#endif