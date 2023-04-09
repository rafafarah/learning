#include <map>
#include "User.hpp"

class UserSystem
{
private:
    map<string, User> m_users;
public:
    UserSystem();
    ~UserSystem();
    bool RegisterUser(string user, string pass);
    void LogIn(string user, string pass);
};
