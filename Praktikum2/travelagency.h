#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>


#include "booking.h"
#include "travel.h"
#include "customer.h"


using namespace std;


class TravelAgency
{
public:
    TravelAgency();

    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);

    void ausgabeKunden() const;
    void ausgabeReisen() const;

    int createBooking (char type, double price, string start, string end, long travelId, vector<string> bookingDetails);

private:
    vector<Booking*> allBookings;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
};

#endif // TRAVELAGENCY_H
