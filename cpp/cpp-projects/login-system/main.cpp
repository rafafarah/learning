#include <iostream>
#include <fstream>
#include <string>
#include "UserSystem.hpp"

using namespace std;

int main()
{
    int choice, run = 1;
    UserSystem userdb;

    while (run) {
        cout << "1: Register\n2: Login\n3: Exit\nYour choice: "; cin >> choice;

        if (1 == choice) {
            string username, password;

            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;
            cout << "Register status: " << userdb.RegisterUser(username, password) << endl;
        } else if (2 == choice) {
            string username, password;

            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;

            userdb.LogIn(username, password);
        } else if (3 == choice) {
            run = 0;
        }
    }

    return 0;
}
