#ifndef BOOKING_H
#define BOOKING_H

#include<string>
#include <iostream>
using namespace std;


class Booking
{
public:
    Booking();

    long getId() const; //getter für id

protected:
    long id;
    double price;
    long travelID;
    string fromDate;
    string toDate;
};

#endif // BOOKING_H
