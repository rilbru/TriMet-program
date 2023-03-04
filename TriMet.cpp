/*****************************************************************************
# Author:           Devri Anderson 
# Lab:              Assignment #4
# Date:             October 20, 2021
# Description:      Select your pass type and number of passes to see the cost to ride on the TriMet.
# Input:            passType, numTickets   
# Output:           numTickets, amountPaid, freeRide
# Sources:          ZyBooks Ch. 4
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Setting fastpass pricing as constants 
const double ADULT_PASS = 2.50;
const double HY_PASS = 1.25;

int main() 
{
 // Declaring data types
 char passType = ' ';
 int numTickets = 0;
 double amountPaid = 0.00;
 double freeRide = 0.00;

 // Display welcome prompt menu
 cout << fixed << setprecision(2);
 cout << "Welcome to TriMet Hop Fastpass!" << endl << endl;
 cout << setw(40) << left << "Fastpass Choices" << right << "Ticket $" << endl;
 cout << setfill('-') << setw(38) << "" << "  ";
 cout << setfill('-') << setw(8) << "" << endl;
 cout << left << "A. Adult (ages 16-64) ";
 cout << setfill(' ') << setw(24) << right << "$2.50" << endl;
 cout << left << "H. Honored Citizen (65+, disabilities) ";
 cout << setfill(' ') << setw(7) << right << "$1.25" << endl;
 cout << left << "Y. Youth (ages 7-17) ";
 cout << setfill(' ') << setw(25) << right << "$1.25" << endl << endl;

 cout << "Note: Ride for 2 hours and 30 minutes with each ticket." << endl << endl;
 cout << "Ride free for the rest of the month after spending $100 " << endl;
 cout << "with an Adult pass, or $28 with an Honored Citizen or" << endl;
 cout << "Youth pass!" << endl << endl;

 // User is prompted to enter their fastpass choice
 cout << "Enter Fastpass (A, H, Y): ";
 cin >> passType;
 cout << endl;

 if ((passType == 'A') || (passType == 'a') || (passType == 'H') || (passType == 'h') || (passType == 'Y') || (passType == 'y')) 
 {
   cout << "Enter the number of tickets purchased this month: ";
   cin >> numTickets;
   cout << endl;
   // Defining each fastpass pricing & freeRide 
   if ((passType == 'A') || (passType == 'a')) 
   {                      
    amountPaid = (ADULT_PASS * numTickets);
    freeRide = (100.00 - amountPaid);
   }
   else if ((passType == 'H') || (passType == 'h') || (passType == 'Y') || (passType == 'y')) 
   { 
    amountPaid = (HY_PASS * numTickets);
    freeRide = (28.00 - amountPaid);
   }
   // Display message for user who gets free rides 
   if (freeRide <= 0)
   {             
    cout << "You have purchased " << numTickets << " ticket(s)!" << endl;
    cout << "You have paid: $ " << amountPaid << endl;
    cout << "Congratulations! You have earned free rides for the rest of  the month!" << endl << endl;   
   }
   // Display tickets purchased and amount needed to spend to earn free rides
   else if (freeRide > 0)  
   {
    cout << "You have purchased " << numTickets << " ticket(s)!" << endl;
    cout << "You have paid: $ " << amountPaid << endl;
    cout << "Spend $ " << freeRide << " more to earn free rides for the rest of the month." << endl << endl;
   }
  }
  else 
   {                             
    cout << "Invalid entry, please try again!" << endl << endl;     
   }
  
 
  cout << "Thank you for riding TriMet!" << endl;
  return 0;
}