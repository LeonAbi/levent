TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    travelagency.cpp \
    rentalcarreservation.cpp \
    hotelbooking.cpp \
    flightbooking.cpp \
    booking.cpp \
    travel.cpp \
    customer.cpp

HEADERS += \
    travelagency.h \
    rentalcarreservation.h \
    hotelbooking.h \
    flightbooking.h \
    booking.h \
    travel.h \
    customer.h
