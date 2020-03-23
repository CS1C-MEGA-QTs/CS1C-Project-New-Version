/******************************************************************************
 * PROGRAMMERS: - Jonathan Aguirre
 *              - Tina     Faraji
 *              - Suhyr    Hasan
 *              - Weston   Mathews
 * CLASS      : CS1C
 * SECTION    : MW 5:00p - 7:30p
 * DUE DATE   : 02/23/20
 *****************************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
public:
    Customer()
    {
        company="Comapny Name";
        address="123 street, city, state, 92620";
        key = "not key";
        interest="never call me again";
    }
    Customer(QString company, QString address, QString key, QString interest)
    {
        this->company=company;
        this->address=address;
        this->key=key;
        this->interest=interest;
    }
    Customer(const  Customer& old)
    {
        company=old.company;
        address=old.address;
        key=old.key;
        interest=old.interest;
    }

    QString getCompany(){return company;}
    QString getAddress(){return address; }
    QString getKey(){return key;}
    QString getInterest(){return interest; }

private:
    QString company;
    QString address;
    QString key;
    QString interest;

};


#endif // CUSTOMER_H
