#include "hotelbooking.h"

/*HotelBooking::HotelBooking(string a1, string a2, string a3, string a4, string a5, string a6)
{
    id = stol(a1);
    price = stod(a2);
    fromDate = a3;
    toDate = a4;
    hotel = a5;
    town = a6;
}*/

HotelBooking::HotelBooking(string s1,string s2,string s3,string s4,string s5,string s6,string s7)
{
    id = stol(s1);
    price = stod (s2);
    travelID = stol(s3);
    fromDate = s4;
    toDate = s5;
    hotel = s6;
    town = s7;

}
