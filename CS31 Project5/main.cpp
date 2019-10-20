#include <iostream>
#include <string>
#include <cassert>

#include "Ticket.h"
#include "BoxOffice.h"
#include "Project5Helper.h"

using namespace std;

int main()
{
    // test code
    
    
    Ticket t( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    BoxOffice b;
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() ==  "Dodger Stadium" );
    assert( t.getEvent() == "Dodgers vs. Brewers" );
    assert( t.getDayTime() == "August 1, 7:30PM" );
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getVenue() ==  "Royce Hall" );
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getDayTime() == "September 1, 7:30PM" );
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    assert( t.getVenue() ==  "Royce Hall" );
    assert( t.getEvent() == "An Evening With David Sedaris" );
    assert( t.getDayTime() == "October 1, 7:30PM" );
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getVenue() ==  "Royce Hall" );
    assert( t.getEvent() == "Barry Manilow Live In Concert" );
    assert( t.getDayTime() == "November 1, 7:30PM" );
    
    t = b.buyRoyceHallTicket( "Balcony Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30" );
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Balcony Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getVenue() ==  "Royce Hall" );
    assert( t.getEvent() == "Barry Manilow Live In Concert" );
    assert( t.getDayTime() == "November 1, 7:30" );
    
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30" );
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    assert( t.getVenue() ==  "Royce Hall" );
    assert( t.getEvent() == "Barry Manilow Live In Concert" );
    assert( t.getDayTime() == "November 1, 7:30" );
    
    cout << "all tests passed!" << endl ;
    
    return 0;
    
    }
