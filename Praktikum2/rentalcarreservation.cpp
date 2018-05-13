#include "rentalcarreservation.h"

/*RentalCarReservation::RentalCarReservation(string a1, string a2, string a3, string a4, string a5, string a6,string a7)
{
    id = stol(a1);
    price = stod(a2);
    fromDate = a3;
    toDate = a4;
    pickupLocation = a5;
    returnLocation = a6;
    company = a7;
}
*/

RentalCarReservation::RentalCarReservation(string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8)
{
    id = stol(s1);
    price = stod (s2);
    travelID = stol(s3);
    fromDate = s4;
    toDate = s5;
    pickupLocation = s6;
    returnLocation = s7;
    company = s8;
}
