#include "flightbooking.h"

FlightBooking::FlightBooking(string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8)
{
    id = stol(s1);
    price = stod (s2);
    travelID = stol(s3);
    fromDate = s4;
    toDate = s5;
    fromDest = s6;
    toDest = s7;
    airline = s8;


}
