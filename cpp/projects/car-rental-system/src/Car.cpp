#include "Car.hpp"

Car::Car(string pn, string b, string m, string c, string t, 
        float mp, float rph, float rp12h, float rpd) :
        m_plateNumber(pn), m_brand(b), m_model(m), m_color(c), 
        m_transmission(t), m_motorPower(mp), m_ratePerHour(rph),
        m_ratePer12Hours(rp12h), m_ratePerDay(rpd) {
}

Car::~Car() {
}

void Car::displayInfo() {
    cout << *this << endl;
}

ostream & operator << (ostream &out, const Car &car)
{
    out << car.m_brand << ", "
        << car.m_model << ", "
        << car.m_color << ", "
        << car.m_transmission << ", "
        << car.m_motorPower << ", "
        << car.m_plateNumber << ", "
        << car.m_ratePerHour << ", "
        << car.m_ratePer12Hours << ", "
        << car.m_ratePerDay;
    return out;
}

const string& Car::getPlateNumber() const {
    return m_plateNumber;
}

const string& Car::getBrand() const {
    return m_brand;
}

const string& Car::getModel() const {
    return m_model;
}

const string& Car::getColor() const {
    return m_color;
}

const string& Car::getTransmission() const {
    return m_transmission;
}

const float& Car::getMotorPower() const {
    return m_motorPower;
}

const float& Car::getRatePerHour() const {
    return m_ratePerHour;
}

const float& Car::getRatePer12Hours() const {
    return m_ratePer12Hours;
}

const float& Car::getRatePerDay() const {
    return m_ratePerDay;
}
