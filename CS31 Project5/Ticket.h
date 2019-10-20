#ifndef Ticket_h
#define Ticket_h
#include <string>

#include <stdio.h>

class Ticket
{
    
public:
    
    enum KIND{ ATHLETICGAME, CONCERT, MOVIE, OTHER};

    Ticket(std::string row, int seat, std::string event, std::string venue, double price, KIND kind, std::string daytime);
    std::string getRow();
    int getSeat();
    std::string getEvent();
    std::string getVenue();
    double getPrice();
    void setPrice( double price);
    KIND getKind();
    std::string getDayTime();
    
private:
    std::string mRow;
    int mSeat;
    std::string mEvent;
    std::string mVenue;
    double mPrice;
    KIND mKind;
    std::string mDayTime;

};

#endif /* Ticket_hpp */
