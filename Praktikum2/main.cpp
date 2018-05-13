#include <iostream>
#include "travelagency.h"
#include <string>
#include <vector>


using namespace std;

int main()
{

    TravelAgency travelAgency;

    travelAgency.readFile();
    travelAgency.ausgabeKunden();
    travelAgency.ausgabeReisen();

    char type;
    double price;
    string start; string end;
    long travelId;
    vector<string> bookingDetails;

    cout << "Bitte Buchungstyp(R, F oder H) eingeben: ";
    cin >> type;
    cout << "Bitte Preis(Ohne Waehrung) eingeben: ";
    cin >> price;
    cout << "Bitte Start-Datum und End-Datum im Format JJJJMMTT eingeben: ";
    cin >> start >> end;
    cout << "Bitte ID der Reise eingeben: ";
    cin >> travelId;

    string sEingabe;

    switch(type){
    case 'R': cout << "Bitte Abholstation eingeben: ";
        cin >> sEingabe;
                      bookingDetails.push_back(sEingabe);
                cout << "Bitte Rueckgabestation eingeben: ";
                cin >> sEingabe;
                bookingDetails.push_back(sEingabe);
                cout << "Bitte Autoverleihfirma eingeben: ";
                cin >> sEingabe;
                        bookingDetails.push_back(sEingabe);
        break;
    case 'F':
        cout << "Bitte Startflughafen eingeben: ";
                              cin >> sEingabe;
                              bookingDetails.push_back(sEingabe);
                        cout << "Bitte Zeilflughafen eingeben: ";
                        cin >> sEingabe;
                        bookingDetails.push_back(sEingabe);
                        cout << "Bitte Fluglinie eingeben: ";
                                cin >> sEingabe;
                                bookingDetails.push_back(sEingabe);
        break;
case 'H':
        cout << "Bitte Hotelname eingeben: ";
        cin >> sEingabe;
                      bookingDetails.push_back(sEingabe);
                        cout << "Bitte Stadt eingeben: ";
                        cin >> sEingabe;
                                      bookingDetails.push_back(sEingabe);
break;
    default: cerr << "Typ nicht gefunden!"<< endl;
    }


    travelAgency.createBooking(type, price,start, end, travelId, bookingDetails);

    return 0;
}
