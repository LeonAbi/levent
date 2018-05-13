#include "travelagency.h"
#include "rentalcarreservation.h"
#include "flightbooking.h"
#include "hotelbooking.h"
TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile()
{

    int iAnzFlugReservierungen = 0;
    int iAnzHotelReservierungen = 0;
    int iAnzMietwagenReservierungen = 0;
    double iGesamtWert = 0;
    int iAnzReisen = 0;
    int iAnzKunden = 0;

    ifstream dateiIn;
    dateiIn.open("/Users/Leventcln/Praktikum2/bookings2.txt",ios::in);
    if(!dateiIn) {
        cerr<<" kann nicht geoeffnet werden! \n";
        exit(-1);
    }
    while(!dateiIn.eof()){
        string zeile;
        getline(dateiIn, zeile);
        stringstream zeilenpuffer(zeile);

        string sBuchungstyp;

        getline(zeilenpuffer, sBuchungstyp, '|');

        char cSwitch =sBuchungstyp[0];
        int iZaehler = 9;
        if(cSwitch == 'F' || cSwitch == 'R'){
            iZaehler = 10;
        }
        string sArray[iZaehler];
        for( int ui= 0; ui < iZaehler;++ui){
            getline(zeilenpuffer, sArray[ui], '|');

        }

        /*
sArray[0] = ID der Buchung
       1 = Preis der Buchung
       2 = fromDate
       3 = toDate
       4 = Id der Reise
       5 = id des Kunden
       6 = NAme des Kunden
       7 = f = fromDest
           r = pickupLocation
           h = toDest
       8 = f = toDest
           r = returnLocation
           h = town
       9 = f = airline
           r= company

*/

        Customer *customer = findCustomer(stol(sArray[5]));
        if(customer == nullptr){
            customer = new Customer(stol(sArray[5]), sArray[6]);
            allCustomers.push_back(customer);
            ++iAnzKunden;
        }

        Travel *travel = findTravel(stol(sArray[4]));
        if(travel == nullptr){
            travel = new Travel(stol(sArray[4]), customer->getId());
            customer->addTravel(travel);
            allTravels.push_back(travel);
            ++iAnzReisen;

        }

        Booking *booking = findBooking(stol(sArray[0]));
        if(booking == nullptr){

            switch (cSwitch) {
            case 'R':{

                booking = new RentalCarReservation(sArray[0],sArray[1],sArray[2],sArray[3],sArray[4],sArray[7],sArray[8],sArray[9]);
                travel->addBookings(booking);
                allBookings.push_back(booking);
                ++iAnzMietwagenReservierungen;
                iGesamtWert += stod(sArray[1]);

            }

                break;

            case 'F': {

                booking = new FlightBooking(sArray[0],sArray[1],sArray[2],sArray[3],sArray[4],sArray[7],sArray[8],sArray[9]);
                travel->addBookings(booking);
                allBookings.push_back(booking);
                ++iAnzFlugReservierungen;
                iGesamtWert += stod(sArray[1]);

            }

                break;
            case 'H': {

                booking = new HotelBooking(sArray[0],sArray[1],sArray[2],sArray[3],sArray[4],sArray[7],sArray[8]);
                travel->addBookings(booking);
                allBookings.push_back(booking);
                ++iAnzHotelReservierungen;
                iGesamtWert += stod(sArray[1]);
            }
                break;
            default:
                cout << " Ein fehler ist aufgetretten: Unbekannte Buchung!";
                exit(1);
                break;
            }
        }
    }

    dateiIn.close();

    cout << "Es wurden " << iAnzFlugReservierungen << " Flugreservierungen, " << iAnzHotelReservierungen << " Hotelreservierungen und " << iAnzMietwagenReservierungen << " Mietwagenreservierungen im Gesamtwert von "<< iGesamtWert << " eingelesen.";
    cout << " Es wurden " << iAnzReisen << " Reisen und " << iAnzKunden << " Kunden angelegt. Der Kunde mit der ID 1 hat " << findCustomer(1)->getAnzReisen()<< " Reisen gebucht. Zur Reise mit der ID 17 gehoeren "<< findTravel(17)->getAnzBuchungen()<< " Buchungen." << endl <<endl;

    return;
}

Booking *TravelAgency::findBooking(long id)
{
    for(unsigned int i = 0; i < allBookings.size(); ++i){
        if(allBookings.at(i)->getId() == id){
            return allBookings.at(i);
        }
    }
    return nullptr;
}

Travel *TravelAgency::findTravel(long id)
{
    for(unsigned int i = 0; i < allTravels.size(); ++i){
        if(allTravels.at(i)->getId() == id){
            return allTravels.at(i);
        }
    }
    return nullptr;
}

Customer *TravelAgency::findCustomer(long id)
{
    for(unsigned int i = 0; i < allCustomers.size(); ++i){
        if(allCustomers.at(i)->getId() == id){
            return allCustomers.at(i);
        }
    }
    return nullptr;
}

void TravelAgency::ausgabeKunden() const
{
    for(unsigned int ui = 0; ui < allCustomers.size(); ++ui){
        cout << "ID: " <<allCustomers.at(ui)->getId() << " Kundenname: " << allCustomers.at(ui)->getName() << endl;
    }

}

void TravelAgency::ausgabeReisen() const
{
    for(unsigned int ui = 0; ui < allTravels.size(); ++ui){
        cout << "ID: " <<allTravels.at(ui)->getId() << " KundenID: " << allTravels.at(ui)->getCustomerID() << endl;
    }
}

int TravelAgency::createBooking(char type, double price, string start, string end, long travelId, vector<string> bookingDetails)
{
    int iAnzFlugReservierungen = 0;
    int iAnzHotelReservierungen = 0;
    int iAnzMietwagenReservierungen = 0;
    double iGesamtWert = 0;

    bool bFound = false;
    for(unsigned int ui = 0; ui < allTravels.size(); ++ui){
        if(allTravels.at(ui)->getId() == travelId){
            bFound = true;
        }
    }
    if(bFound == false){
        return -1;}


    int iMaxId = 0;
    for(unsigned int ui = 0; ui < allBookings.size(); ++ui){
        if(allBookings.at(ui)->getId() > iMaxId){
            iMaxId = allBookings.at(ui)->getId();
        }
    }
    ++iMaxId;



    switch (type) {
    case 'R':{

        Booking *booking = new RentalCarReservation(to_string(iMaxId) ,to_string(price),start, end,to_string(travelId),bookingDetails[0],bookingDetails[1],bookingDetails[2]);
        allBookings.push_back(booking);
        ++iAnzMietwagenReservierungen;
        iGesamtWert += price;

    }

        break;

    case 'F': {

        Booking *booking = new FlightBooking(to_string(iMaxId),to_string(price),start, end,to_string(travelId),bookingDetails.at(0),bookingDetails.at(1),bookingDetails.at(2));
        allBookings.push_back(booking);
        ++iAnzFlugReservierungen;
        iGesamtWert += price;

    }

        break;
    case 'H': {

        Booking *booking = new HotelBooking(to_string(iMaxId),to_string(price),start, end,to_string(travelId),bookingDetails.at(0),bookingDetails.at(1));
        allBookings.push_back(booking);
        ++iAnzHotelReservierungen;
        iGesamtWert += price;
    }
        break;
    default:
        cout << " Ein fehler ist aufgetretten: Unbekannte Buchung!";
        exit(1);
        break;
    }

     cout << "Es wurden " << iAnzFlugReservierungen << " Flugreservierungen, " << iAnzHotelReservierungen << " Hotelreservierungen und " << iAnzMietwagenReservierungen << " Mietwagenreservierungen im Gesamtwert von "<< iGesamtWert << " eingelesen." << endl;
    return iMaxId;
}
