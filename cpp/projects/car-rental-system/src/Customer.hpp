#include <string>

using namespace std;

class Customer
{
private:
    int m_id;
    string m_name;
    string m_phone;
    string m_ic;
    string m_address;
public:
    Customer();
    ~Customer();
    const int getId() const;
    const string getName() const;
    const string getPhone() const;
    const string getIC() const;
    const string getAddress() const;
};
