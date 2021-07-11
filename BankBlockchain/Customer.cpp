#include "Customer.h"

Customer::Customer() //empty constructor
{

}

Customer::Customer(std::string customerNameSurname,double customerBalance) //empty constructor
{
    setNameSurname(customerNameSurname);
    setBalance(customerBalance);
}

std::string Customer::getNameSurname()
{
    return nameSurname;
}

void Customer::setNameSurname(std::string newNameSurname)
{
    nameSurname=newNameSurname;
}

double Customer::getBalance()
{
    return balance;
}

void Customer::setBalance(double newBalance)
{
    balance=newBalance;
}

std::string Customer::withdraw(double amount)
{
    setBalance(getBalance()-amount);

    return "("+getNameSurname()+","+std::to_string(amount)+",";
}