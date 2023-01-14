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

class UserManager
{
	int idLoggedUser;
	
	vector <User> users;
	User giveDataNewUser(); // podaj dane nowego uzytkownika
	
	UsersFileXml usersFileXml;
	
	 bool loginExists(string login);
	
public: 
	UserManager(string nameUsersFileXml): usersFileXml(nameUsersFileXml)
	{
		idLoggedUser = 0;
		users = usersFileXml.loadUsersFromFileXml();
	}
	
	int getNewUserId();
    int getLoggedUserId();

    void userSignUp(); //rejestracja
    void writeOutAllUsers(); //wypisz wszystkich
    int userSignIn(); //logowanie
    void changePasswordOfLoggedUser(); //zmiana hasla
    void saveAllUsersToFileXml(); //zapisz wszytkich uzytkownikow do pliku
    void userSignOut(); //wulogowaniw
    bool userIsLoggedIn(); // czy uzytkownik jest zalogowany
	
	 bool loginExists();
};
#endif