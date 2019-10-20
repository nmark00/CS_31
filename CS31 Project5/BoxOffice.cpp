#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

BoxOffice::BoxOffice(){}

//         PRICING ALGORITHM
Project5Helper p5h;

double BoxOffice::generalPricing(Ticket::KIND kind, string daytime, string row){
    double price=0;
    
    // PRICING FOR THE KIND
    if (kind== Ticket::ATHLETICGAME) {
        price= 75;
    }
    else if (kind== Ticket::CONCERT) {
        if (p5h.endsWithPM(daytime)) {
            price=65;
        }
        else
            price=50;
    }
    else if (kind== Ticket::MOVIE) {
        price= 12.5;
    }
    else{
        if (p5h.endsWithPM(daytime)) {
            price=55;
        }
        else
            price=40;
    }
    
    // PRICING FOR THE LOCATION
    if(p5h.startsWithOrchestra(row)){
        price *=2;
    }
    
    return price;
}

double BoxOffice::studentDiscount(double initialPrice)
{
    double price=initialPrice;
    if (price>=40) {
        price-=30;
    }
    else
        price *=.8;
    return price;
}
double BoxOffice::staffDiscount(double initialPrice)
{
    double price=initialPrice;
    if (price>=40) {
        price-=20;
    }
    else
        price *=.9;
    return price;
}


//      4 MAIN FUNCTION:

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime){
    return Ticket(row, seat, event, venue, 0.0, kind, daytime);
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime){
    
    return Ticket(row, seat, event, "Royce Hall", studentDiscount(generalPricing( kind, daytime, row)), kind, daytime);
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime){
    return Ticket(row, seat, event, "Royce Hall", staffDiscount(generalPricing( kind, daytime, row)), kind, daytime);
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime){
    return Ticket(row, seat, event, "Royce Hall", generalPricing( kind, daytime, row), kind, daytime);
}
