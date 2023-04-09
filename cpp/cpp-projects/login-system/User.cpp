#include <iostream>
#include "User.hpp"

User::User(string user, string pass) 
    : m_username(user), m_password(pass) {
}

User::~User() {
}

bool User::LogIn(string user, string pass) {
    m_isLoggedIn = 
        (user == m_username && pass == m_password);

    return m_isLoggedIn;
}
