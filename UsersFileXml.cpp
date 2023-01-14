#include "UsersFileXml.h"

vector <User> UsersFileXml::loadUsersFromFileXml() {
    User user;
    vector <User> users;
    
	bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        user = getDataUser();
        users.push_back(user);
    }
    xml.OutOfElem();
    xml.Save(getNameFile());
    return users;
}
    
User UsersFileXml::getDataUser()
{
    User user;
    MCD_STR userId, login, password, name, surname;
    xml.IntoElem();
    xml.FindElem("UserId");
    userId = xml.GetData();
    user.setUserId(atoi(userId.c_str()));

    xml.FindElem("Login");
    login = xml.GetData();
    user.setLogin(login);

    xml.FindElem("Password");
    password = xml.GetData();
    user.setPassword(password);

    xml.FindElem("Name");
    name = xml.GetData();
    user.setName(name);

    xml.FindElem("Surname");
    surname = xml.GetData();
    user.setSurname(surname);

    xml.OutOfElem();

    return user;
}

void UsersFileXml::addUserToFileXml(User user)
{
    bool fileExists = xml.Load( getNameFile());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", HelperMethods::conversionIntToString(user.getUserId()));
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.Save(getNameFile());
}

void UsersFileXml::saveAllUsersToFileXml(int idLoggedUser, string password)
{
    vector <User> users = loadUsersFromFileXml();

    deleteFileXml(getNameFile());

    bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();

    for (unsigned int i = 0; i < users.size(); i++)
    {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", HelperMethods::conversionIntToString(users[i].getUserId()));
        xml.AddElem("Login", users[i].getLogin());
        if (users[i].getUserId() == idLoggedUser )
        {
            xml.AddElem("Password", password);
        }
        else
        {
            xml.AddElem("Password", users[i].getPassword());
        }
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
                    xml.OutOfElem();
    }
    xml.Save(getNameFile());
}


void UsersFileXml::deleteFileXml(string nameFileToDelete)
{
    if (remove(nameFileToDelete.c_str()) == 0) {}
    else
        cout << "File can`t be deleted." << nameFileToDelete << endl;
}