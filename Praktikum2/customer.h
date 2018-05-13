#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"


class Customer
{
public:
    Customer(long, string );

    void addTravel(Travel* travel);

    long getId() const;

    int getAnzReisen() const;

    string getName() const;

private:
    long id;
    string name;
    vector<Travel*> travelList;
};

#endif // CUSTOMER_H
