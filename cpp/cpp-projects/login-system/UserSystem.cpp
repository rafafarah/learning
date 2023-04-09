#include <iostream>
#include "UserSystem.hpp"

UserSystem::UserSystem() {
}

UserSystem::~UserSystem() {
}

bool UserSystem::RegisterUser(string user, string pass) {
    auto ret = m_users.insert(make_pair(user, User(user, pass)));
    return ret.second;
}

void UserSystem::LogIn(string user, string pass) {
    auto usermapped = m_users.find(user);
    if (usermapped != m_users.end()) {
        if (usermapped->second.LogIn(user, pass)) {
            cout << "Log in successfully!" << endl;
        } else {
            cout << "Password incorrect!" << endl;
        }
    } else {
        cout << "User " << user << " not found!" << endl;
    }
}
