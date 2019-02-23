//
//  Ticket.cpp
//  Project5
//
//  Created by Bryan Wong on 2/20/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include "Ticket.h"

using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime) { // constructor
    
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mKind = kind;
    mDayTime = daytime;
    
}

// getters and setters
string Ticket::getRow() {
    return mRow;
}

int Ticket::getSeat() {
    return mSeat;
}

string Ticket::getEvent() {
    return mEvent;
}

string Ticket::getVenue() {
    return mVenue;
}

double Ticket::getPrice() {
    return mPrice;
}

void Ticket::setPrice(double price) {
    mPrice = price;
}

Ticket::KIND Ticket::getKind() {
    return mKind;
}

string Ticket::getDayTime() {
    return mDayTime;
}
