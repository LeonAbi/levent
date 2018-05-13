#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include <string>
#include "booking.h"
using namespace std;

class HotelBooking : public Booking
{
public:
    HotelBooking(string,string,string,string,string,string,string);
private:
    string hotel;
    string town;
};

#endif // HOTELBOOKING_H
