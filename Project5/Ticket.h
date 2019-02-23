//
//  Ticket.h
//  Project5
//
//  Created by Bryan Wong on 2/20/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>

using namespace std;

class Ticket {
  
public:
    
    enum KIND { ATHLETICGAME, CONCERT, MOVIE, OTHER}; // enumerated variable KIND - Values 0-3

    Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime); // constructor
    
    // getters and setters
    string getRow();
    int getSeat();
    string getEvent();
    string getVenue();
    double getPrice();
    void setPrice(double price);
    KIND getKind();
    string getDayTime();
    
private:
    string mRow;
    int mSeat;
    string mEvent;
    string mVenue;
    double mPrice;
    KIND mKind;
    string mDayTime;
    
};


#endif /* Ticket_h */
