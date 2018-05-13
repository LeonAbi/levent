#include "travel.h"

Travel::Travel(long l1, long l2)
{
    id = l1;
    customerID = l2;
}

void Travel::addBookings(Booking *booking)
{
    travelBookings.push_back(booking);
}

long Travel::getId() const
{
    return id;
}

int Travel::getAnzBuchungen() const
{
    return travelBookings.size();
}

long Travel::getCustomerID() const
{
    return customerID;
}
