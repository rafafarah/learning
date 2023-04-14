#include "Customer.hpp"

Customer::Customer() {
}

Customer::~Customer() {
}

const int Customer::getId() const {
    return m_id;
}

const string Customer::getName() const {
    return m_name;
}

const string Customer::getPhone() const {
    return m_phone;
}

const string Customer::getIC() const {
    return m_ic;
}

const string Customer::getAddress() const {
    return m_address;
}
