//
//  BoxOffice.cpp
//  Project5
//
//  Created by Bryan Wong on 2/20/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include "BoxOffice.h"
#include "Project5Helper.h"

using namespace std;

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime) {
    Ticket soldTicket(row, seat, event, venue, 0, kind, daytime); // price set to zero by default
    return soldTicket;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    // generate the ticket
    Ticket soldTicket = buyTicket(row, seat, event, "Royce Hall", kind, daytime);
    
    // calculate price
    Project5Helper tester;
    double price = 0;
    
    if(kind == Ticket::ATHLETICGAME) { // Athletic games always cost $75
        price = 75.00;
    }
    else if(kind == Ticket::CONCERT) {
        if(tester.endsWithPM(daytime)) // time of the concert is in PM
            price = 65.00;
        else price = 50.00; // time of concert is in AM
    }
    else if(kind == Ticket::MOVIE) {
        price = 12.50;
    }
    else if(kind == Ticket::OTHER) {
        if(tester.endsWithPM(daytime)) // time of the concert is in PM
            price = 55.00;
        else price = 40.00; // time of concert is in AM
    }
    
    if(tester.startsWithOrchestra(row) == true) // if these are orchestra seats, double the price
        price *= 2;
    
    // set the ticket's price
    soldTicket.setPrice(price);
    return soldTicket;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    Project5Helper tester;
    
    Ticket soldTicket = buyRoyceHallTicket(row, seat, event, kind, daytime); // create a general price Ticket
    double price = soldTicket.getPrice(); // store general price in double
    
    // since this function is for students, apply student discount
    if(price >= 40.00) {
        price -= 30.00;
    } else price *= 0.8;

    soldTicket.setPrice(price); // set the ticket's price to the discounted value
    return soldTicket; // return ticket
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    Project5Helper tester;
    
    Ticket soldTicket = buyRoyceHallTicket(row, seat, event, kind, daytime); // create a general price Ticket
    double price = soldTicket.getPrice(); // store general price in double
    
    // since this function is for staff, apply staff discount
    if(price >= 40.00) {
        price -= 20.00;
    } else price *= 0.9;
    
    soldTicket.setPrice(price); // set the ticket's price to the discounted value
    return soldTicket; // return ticket
}



