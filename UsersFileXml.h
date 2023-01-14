#ifndef USERSFILEXML_H
#define USERSFILEXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelperMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class UsersFileXml : public FileXml
{
	CMarkup xml;
	
	User getDataUser();
	void deleteFileXml(string nameFileToDelete);
	
public:
    UsersFileXml(string nameUsersFileXml) : FileXml(nameUsersFileXml) {};
    
     vector <User> loadUsersFromFileXml();
     
     void addUserToFileXml(User user);
     void saveAllUsersToFileXml(int idLoggedUser, string password);
};
#endif