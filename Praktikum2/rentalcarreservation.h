#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <string>
#include "booking.h"

using namespace std;

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(string,string,string,string,string,string,string,string);

private:
    string pickupLocation;
    string returnLocation;
    string company;

};

#endif // RENTALCARRESERVATION_H
