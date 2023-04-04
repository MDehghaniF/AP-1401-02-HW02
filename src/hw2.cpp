// Mojtaba Dehghani Firouzabadi 9923027
// Advance Programming Dr. Amir Jahanshahi
// 1401/12/29 eydeton mobark =)))

#include "../include/hw2.h"

User::User(std::string name, std::string pass, std::string mail) // ✔
{
    username = name;
    password = pass;
    email = mail;
}
User::~User() // ✔
{
}

Login::Login() // ✔
{
}

Login::~Login() // ✔
{
    LoginedUsers.clear();
    for (size_t i {}; i < users.size(); i++) {
        delete users[i];
    }
}

void Login::readFile(std::string path) // reads the .txt file, then register the user inside readFile using theregisterUser function ✔
{
    std::fstream ifs { path };
    std::string line;
    std::getline(ifs, line);
    while (!ifs.eof()) {
        std::getline(ifs, line);
        std::istringstream iss { line };
        std::string user, pass, mail, log;
        iss >> user >> pass >> mail >> log;
        registerUser(user, pass, mail);
        if (log == "yes")
            loginUser(user, pass);
    }
    ifs.close();
}

bool Login::checkUsername(std::string& new_username) // checks if the user is already taken, if so, it returns true and the username shouldn't be created ✔
                                                     // and prints "username already taken" ✔
{
    if (getUser(new_username) == nullptr) {
        return false;
    }
    std::cout << "username already taken" << std::endl;
    return true;
}

bool Login::checkEmail(std::string& new_email) // only new emails may be pushedback to "emails" vector ✔
{
    bool tmp { false };
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->email == new_email) {
            tmp = true;
            break;
        }
    }
    return tmp;
}

void Login::changeUsername(std::string username, std::string newUsername) // ✔
{
    getUser(username)->username = newUsername;
}

void Login::changePassword(std::string username, std::string newPassword) // ✔
{
    getUser(username)->password = newPassword;
}

void Login::changeMail(std::string username, std::string newMail) // ✔
{
    getUser(username)->email = newMail;
}

void Login::registerUser(std::string username, std::string password, std::string email) // function to creat a user ✔
{
    if (!(checkEmail(email) || checkUsername(username))) {
        users.push_back(new User { username, password, email });
    }
}

void Login::loginUser(std::string username, std::string password) // ✔
{
    User* user { getUser(username) };
    if (user->password == password) {
        LoginedUsers.push_back(user);
    }
}

void Login::removeUser(std::string username) // ✔
{
    for (size_t i {}; i < LoginedUsers.size(); i++) {
        if (LoginedUsers[i]->username == username) {
            LoginedUsers.erase(LoginedUsers.begin() + i);
            break;
        }
    }
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->username == username) {
            delete users[i];
            users.erase(users.begin() + i);
            break;
        }
    }
}

User* Login::getUser(std::string username) // returns the usernames using the same email, returns false if that email doesnt exist ✔
{
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i]->username == username) {
            return users[i];
        }
    }
    return nullptr;
}
