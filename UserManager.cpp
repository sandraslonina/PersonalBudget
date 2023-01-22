#include "UserManager.h" 

void UserManager::userSignUp() 
{
    User user = giveDataNewUser();

    users.push_back(user);

    usersFileXml.addUserToFileXml(user);

    cout << endl << "New account has been created!" << endl << endl;
    
    system("pause");
}

User UserManager::giveDataNewUser()
 {
    User user;

    user.setId(getNewId());

    string login = "", password = "", name = "", surname = "";

    do {
        cout << "Create a new login: ";
		login = HelperMethods::getTheLine();
        user.setLogin(login);

    } while (loginExists(user.getLogin()) == true);
    
    cout << "Create a password: ";
    password = HelperMethods::getTheLine();
    user.setPassword(password);
    
    cout << "Give your name: ";
    name = HelperMethods::getTheLine();
    user.setName(name);
        
    cout << "Give your surname: ";
    surname = HelperMethods::getTheLine();
    user.setSurname(surname);

    return user;
}

int UserManager::getNewId() {
    if (users.empty() == true)
        return 1;

    else
        return users.back().getId() + 1;
}

bool UserManager::loginExists(string login)
{
    for (unsigned int i = 0; i <users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "The login you have entered is already registered!" << endl;
            return true;
        }
    }

    return false;
}

void UserManager::writeOutAllUsers() {
    for (unsigned int i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

int UserManager::userSignIn() {
    User user;
    string login = "", password = "";

    cout << endl << "Please enter your login and password below" << endl;
    cout << "Enter your login: ";
    login = HelperMethods::getTheLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attempts = 3; attempts > 0; attempts--) {
                cout << "Enter your password. Remained attempts: " << attempts << ": ";
                password = HelperMethods::getTheLine();

                if (itr -> getPassword() == password) {

                    cout << endl << "You`re logged in!" << endl << endl;
                    system("pause");
                    idLoggedUser = itr -> getId();
                    return idLoggedUser;
                }
            }

            cout << "You entered three incorrect passwords." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }

    cout << "Sorry, this login doesn`t exists." << endl << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedUserId() {
    return idLoggedUser;
}

void UserManager::changePasswordOfLoggedUser() {

    string newPassword = "";
    cout << "Create a new password: ";
    newPassword = HelperMethods::getTheLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == idLoggedUser) {
            itr -> setPassword(newPassword);
            cout << "Your password has been changed!" << endl << endl;
            system("pause");
        }
    }

    usersFileXml.saveAllUsersToFileXml(idLoggedUser,newPassword);
}

void UserManager::userSignOut() {
    if (idLoggedUser == 0)
        cout << "No one is singed in!" << endl;

    else {
        vector <User>::iterator itr = users.begin();

        while (itr != users.end()) {
            if (itr -> getId() == idLoggedUser)
                break;

            itr++;
        }

        cout << "User: " << itr -> getLogin() << " is signed-out." << endl;
        idLoggedUser = 0;
        Sleep(1000);
    }
}

bool UserManager::userIsLoggedIn() {
    if (idLoggedUser > 0)
        return true;

    else
        return false;
}