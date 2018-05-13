#include "customer.h"

Customer::Customer(long l1, string s1)
{
    id = l1;
    name = s1;
}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}

long Customer::getId() const
{
    return id;
}

int Customer::getAnzReisen() const
{
    return travelList.size();
}

string Customer::getName() const
{
    return name;
}

