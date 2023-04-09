#include <string>

using namespace std;

class User
{
private:
    string m_username;
    string m_password;
    bool m_isLoggedIn;

public:
    User(string user, string pass);
    ~User();
    bool LogIn(string username, string password);
};
