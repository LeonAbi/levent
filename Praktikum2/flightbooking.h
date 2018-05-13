#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <string>
#include "booking.h"
using namespace std;


class FlightBooking : public Booking
{
public:
    FlightBooking(string,string,string,string,string,string,string,string);
private:
    string fromDest;
    string toDest;
    string airline;
};

#endif // FLIGHTBOOKING_H
