#include <iostream>
using namespace std;
#include <string>

int main()
{
    string kindValue;
    string mealValue;
    string typeValue;
    string residentValue;
    double price=0;
    bool goodanswer;
    
    cout.setf( ios::showpoint );
    cout.setf( ios::fixed );
    cout.precision( 2 );

// test for kind
    cout << "Ticket or BruinCard? ";
    getline(cin, kindValue);
    if( kindValue == "Ticket" || kindValue == "BruinCard")
    {
        goodanswer = true;
    }
    
    else
        goodanswer = false;
    
    if (goodanswer == false) {
        cout << "The kind value must either be Ticket or BruinCard.";
        cout << "\n";
        return (-1);
    }
    
    
// test for meal
    cout << "Breakfast, Lunch or Dinner? ";
    getline(cin, mealValue);
    if (mealValue == "Breakfast" || mealValue == "Lunch" || mealValue == "Dinner")
        cout << "";
    else
        goodanswer = false;
    
    if (goodanswer == false) {
        cout << "The meal value must either be Breakfast, Lunch or Dinner.";
        cout << "\n";
        return (-1);
    }
    
// TICKET PRICE
    if( kindValue == "Ticket" && mealValue == "Breakfast")
    {
        price = 12.50;
    }
    if( kindValue == "Ticket" && mealValue == "Lunch")
    {
        price = 14.50;
    }
    if( kindValue == "Ticket" && mealValue == "Dinner")
    {
        price = 17.00;
    }
    
    if (kindValue == "Ticket") {
        cout << "Thank you for eating at UCLA today.  Your meal cost is $";
        cout << price;
        cout << ".\n";
        return (0);
    }
    
// test for type
    cout << "Student or Staff? ";
    getline(cin, typeValue);
    if (typeValue == "Student" || typeValue == "Staff")
        cout << "";
    else
        goodanswer = false;
    
    if (goodanswer == false) {
        cout << "The type value must either be Student or Staff.";
        cout << "\n";
        return (-1);
    }
// STAFF PRICE
    if( typeValue == "Staff" && mealValue == "Breakfast")
    {
        price = 11.25;
    }
    if( typeValue == "Staff" && mealValue == "Lunch")
    {
        price = 12.75;
    }
    if( typeValue == "Staff" && mealValue == "Dinner")
    {
        price = 14.75;
    }
    
    if (typeValue == "Staff") {
        cout << "Thank you for eating at UCLA today.  Your meal cost is $";
        cout << price;
        cout << ".\n";
        return (0);
    }

    
// test for resident
    cout << "Resident? ";
    getline(cin, residentValue);
    if (residentValue == "Yes" || residentValue == "No")
        cout << "";
    else
        goodanswer = false;
    
    if (goodanswer == false) {
        cout << "The resident value must either be Yes or No.";
        cout << "\n";
        return (-1);
    }


// STUDENT RESIDENT PRICE
    
    if (kindValue == "BruinCard" && mealValue == "Breakfast" && typeValue == "Student" && residentValue == "Yes") {
        price = 9.75;
    }
    if (kindValue == "BruinCard" && mealValue == "Lunch" && typeValue == "Student" && residentValue == "Yes") {
        price = 11.25;
    }
    if (kindValue == "BruinCard" && mealValue == "Dinner" && typeValue == "Student" && residentValue == "Yes") {
        price = 12.25;
    }

// STUDENT NONRES PRICE
    if (kindValue == "BruinCard" && mealValue == "Breakfast" && typeValue == "Student" && residentValue == "No") {
        price = 10.00;
    }
    if (kindValue == "BruinCard" && mealValue == "Lunch" && typeValue == "Student" && residentValue == "No") {
        price = 11.75;
    }
    if (kindValue == "BruinCard" && mealValue == "Dinner" && typeValue == "Student" && residentValue == "No") {
        price = 12.75;
    }

    cout << "Thank you for eating at UCLA today.  Your meal cost is $";
    cout << price;
    cout << ".\n";
    return (0);

}
