#ifndef TRAVEL_H
#define TRAVEL_H
#include <vector>
#include "booking.h"


class Travel
{
public:
    Travel(long, long);
    void addBookings(Booking* booking);
    long getId() const;
    int getAnzBuchungen() const;

    long getCustomerID() const;

private:
    long id;
    long customerID;
    vector<Booking*>travelBookings;
};

#endif // TRAVEL_H
