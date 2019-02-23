//
//  BoxOffice.h
//  Project5
//
//  Created by Bryan Wong on 2/20/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#ifndef BOXOFFICE_H
#define BOXOFFICE_H

#include <iostream>
#include <string>
#include "Ticket.h"

using namespace std;

class BoxOffice {
    
public:
    
    Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    
};

#endif

