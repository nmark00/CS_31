#ifndef BoxOffice_h
#define BoxOffice_h
#include <string>
#include "Ticket.h"
#include <stdio.h>

class BoxOffice
{
public:
    
    BoxOffice();
    Ticket buyTicket(std::string row, int seat, std::string event, std::string venue, Ticket::KIND kind, std::string daytime);
    Ticket buyRoyceHallStudentTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
    Ticket buyRoyceHallStaffTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
    Ticket buyRoyceHallTicket(std::string row, int seat, std::string event, Ticket::KIND kind, std::string daytime);
private:
    double generalPricing(Ticket::KIND kind, std::string daytime, std::string row);
    double studentDiscount(double initialPrice);
    double staffDiscount(double initialPrice);
};

#endif /* BoxOffice_hpp */
