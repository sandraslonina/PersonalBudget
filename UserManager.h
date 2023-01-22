#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFileXml.h"

using namespace std;

class UserManager {
    int idLoggedUser;

    vector <User> users;
    User giveDataNewUser();

    UsersFileXml usersFileXml;

    bool loginExists(string login);

public:
    UserManager(string nameUsersFileXml): usersFileXml(nameUsersFileXml) {
        idLoggedUser = 0;
        users = usersFileXml.loadUsersFromFileXml();
    }
    int getNewId();
    int getLoggedUserId();

    void userSignUp();
    void writeOutAllUsers();
    int userSignIn();
    void changePasswordOfLoggedUser();
    void saveAllUsersToFileXml();
    void userSignOut();
    bool userIsLoggedIn();

};
#endif