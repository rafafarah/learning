#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
    string m_plateNumber;
    string m_brand;
    string m_model;
    string m_color;
    string m_transmission;
    float m_motorPower;
    float m_ratePerHour;
    float m_ratePer12Hours;
    float m_ratePerDay;
public:
    Car(string pn, string b, string m, string c, string t, 
        float mp, float rph, float rp12h, float rpd);
    ~Car();
    void displayInfo();
    const string& getPlateNumber() const;
    const string& getBrand() const;
    const string& getModel() const;
    const string& getColor() const;
    const string& getTransmission() const;
    const float& getMotorPower() const;
    const float& getRatePerHour() const;
    const float& getRatePer12Hours() const;
    const float& getRatePerDay() const;
    friend ostream & operator << (ostream &out, const Car &car);
};
