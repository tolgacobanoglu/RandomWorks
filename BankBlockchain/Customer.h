#ifndef BANKBLOCKCHAIN_CUSTOMER_H
#define BANKBLOCKCHAIN_CUSTOMER_H

#include <iostream>


class Customer
{
    public:
    Customer(std::string,double);
    Customer();
    std::string getNameSurname();
    void setNameSurname(std::string);
    double getBalance();
    void setBalance(double);
    std::string withdraw(double);


    private:
    std::string nameSurname;
    double balance=0;

};

#endif //BANKBLOCKCHAIN_CUSTOMER_H