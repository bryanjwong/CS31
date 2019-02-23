//
//  main.cpp
//  Project5
//
//  Created by Bryan Wong on 2/20/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

#include "Ticket.h"
#include "BoxOffice.h"

int main() {
    
    // set precision to 2 digits
//    cout.setf( ios::showpoint );
//    cout.setf( ios:: fixed );
//    cout.precision( 4 );
    
    //Ticket(string row, int seat, string event, string venue, double price, Kind kind, string daytime); // constructor
    Ticket test("Orchestra Row B", 32, "Derrick's Birthday Party", "The Rat Den", 959.99, Ticket::OTHER, "December 1, 2:30AM");
    
//    cout << "Row: " << test.getRow() << endl;
//    cout << "Seat: " << test.getSeat() << endl;
//    cout << "Event: " << test.getEvent() << endl;
//    cout << "Venue: " << test.getVenue() << endl;
//    cout << "Price: " << test.getPrice() << endl;
//    cout << "Kind: " << test.getKind() << endl;
//    cout << "Day and Time: " << test.getDayTime() << endl;
    
    assert(test.getRow() == "Orchestra Row B");
    assert(test.getSeat() == 32);
    assert(test.getEvent() == "Derrick's Birthday Party");
    assert(test.getVenue() == "The Rat Den");
    assert(test.getPrice() == 959.99);
    assert(test.getKind() == Ticket::OTHER);
    assert(test.getDayTime() == "December 1, 2:30AM");
    
    test.setPrice(50.00);
//    cout << "Price: " << test.getPrice() << endl;
    assert(test.getPrice() == 50.00);
    
    Ticket t( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::ATHLETICGAME, "August 1, 7:30PM" );
    BoxOffice b;
    assert( t.getPrice() == 150.000000 );
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    assert( t.getEvent() == "Dodgers vs. Brewers");
    assert( t.getVenue() == "Dodger Stadium");
    assert( t.getDayTime() == "August 1, 7:30PM");

    // Non-Royce Hall Ticket
    t = b.buyTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", "The Rat Den", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "0.000000" );
    assert( t.getPrice() == 0 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "The Rat Den");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    // ATHLETIC - PM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getPrice() == 150);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "120.000000" );
    assert( t.getPrice() == 120);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getPrice() == 130);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    // ATHLETIC - PM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "75.000000" );
    assert( t.getPrice() == 75);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getPrice() == 45);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getPrice() == 55);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    // ATHLETIC - AM - ORCH : AM does not affect price
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getPrice() == 150);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "120.000000" );
    assert( t.getPrice() == 120);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getPrice() == 130);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    // ATHLETIC - AM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "75.000000" );
    assert( t.getPrice() == 75);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getPrice() == 45);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row A", 12, "World Cup", Ticket::ATHLETICGAME, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getPrice() == 55);
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "World Cup");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    // CONCERT - PM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getPrice() == 130);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "100.000000" );
    assert( t.getPrice() == 100);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getPrice() == 110);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    // CONCERT - PM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "65.000000" );
    assert( t.getPrice() == 65);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getPrice() == 35);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getPrice() == 45);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30PM");
    
    // CONCERT - AM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "100.000000" );
    assert( t.getPrice() == 100);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "70.000000" );
    assert( t.getPrice() == 70);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getPrice() == 80);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    // CONCERT - AM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getPrice() == 50);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getPrice() == 20);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::CONCERT, "November 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "30.000000" );
    assert( t.getPrice() == 30);
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getEvent() == "Barry Manilow Live In Concert");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "November 1, 7:30AM");
    
    // MOVIE - PM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "25.000000" );
    assert( t.getPrice() == 25.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getPrice() == 20.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "22.500000" );
    assert( t.getPrice() == 22.500000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");

    // MOVIE - PM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "12.500000" );
    assert( t.getPrice() == 12.500000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getPrice() == 10.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "11.250000" );
    assert( t.getPrice() == 11.250000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30PM");
    
    // MOVIE - AM - ORCH : AM should not change the price
    
    t = b.buyRoyceHallTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "25.000000" );
    assert( t.getPrice() == 25.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getPrice() == 20.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "22.500000" );
    assert( t.getPrice() == 22.500000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    // MOVIE - AM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "12.500000" );
    assert( t.getPrice() == 12.500000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getPrice() == 10.000000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row U", 20, "Episode VII: The Force Awakens", Ticket::MOVIE, "September 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "11.250000" );
    assert( t.getPrice() == 11.250000 );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Balcony Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "September 1, 7:30AM");
    
    // OTHER - PM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getPrice() == 110);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getPrice() == 80);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "90.000000" );
    assert( t.getPrice() == 90);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    // OTHER - PM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getPrice() == 55);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "25.000000" );
    assert( t.getPrice() == 25);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getPrice() == 35);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30PM");
    
    // OTHER - AM - ORCH
    
    t = b.buyRoyceHallTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getPrice() == 80);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getPrice() == 50);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "60.000000" );
    assert( t.getPrice() == 60);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    // OTHER - AM - BALCONY
    
    t = b.buyRoyceHallTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "40.000000" );
    assert( t.getPrice() == 40);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    t = b.buyRoyceHallStudentTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getPrice() == 10);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getPrice() == 20);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    // ODDS AND ENDS
    
    // Check empty strings and negative price/seat values
    Ticket test2( "", -1, "", "", -1, Ticket::ATHLETICGAME, "" );
    assert( test2.getPrice() == -1 );
    assert( std::to_string( test2.getPrice() ) == "-1.000000" );
    assert( test2.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( test2.getRow() == "" );
    assert( test2.getSeat() == -1 );
    assert( test2.getEvent() == "");
    assert( test2.getVenue() == "");
    assert( test2.getDayTime() == "");
    
    // Check for seat and price with values 0
    Ticket test3( "", 0, "", "", 0, Ticket::ATHLETICGAME, "" );
    assert( test3.getPrice() == 0 );
    assert( std::to_string( test3.getPrice() ) == "0.000000" );
    assert( test3.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( test3.getRow() == "" );
    assert( test3.getSeat() == 0 );
    assert( test3.getEvent() == "");
    assert( test3.getVenue() == "");
    assert( test3.getDayTime() == "");
    
    // If AM/PM is not specified, default to AM pricing
    t = b.buyRoyceHallTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30" );
    assert( std::to_string( t.getPrice() ) == "40.000000" );
    assert( t.getPrice() == 40);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30");
    
    // If Orchestra/Balcony is not specified, defaults to Balcony pricing
    t = b.buyRoyceHallTicket( "Row J", 120, "An Evening With David Sedaris", Ticket::OTHER, "October 1, 7:30AM" );
    assert( std::to_string( t.getPrice() ) == "40.000000" );
    assert( t.getPrice() == 40);
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getVenue() == "Royce Hall");
    assert( t.getDayTime() == "October 1, 7:30AM");
    
    cout << "all tests passed!" << endl ;
    
    return 0;
}

