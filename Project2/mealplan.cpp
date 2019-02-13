//
//  mealplan.cpp
//  mealplan
//
//  Created by Bryan Wong on 1/14/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //variables initialized
    string kind;
    string meal;
    string type;
    string resident;
    double price;
    
    // double values set to include 2 decimal points
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    
    // Questions - if an incompatiable answer is inputted, an appropriate error message will be shown
    // and the int value 1 will be returned, thus ending the program.
    
    // Question 1
    cout << "Ticket or BruinCard? ";
    getline(cin, kind);
    
    // If the response to question 1 is not "Ticket" or "BruinCard", an error message is returned
    if(kind != "Ticket" && kind != "BruinCard") {
        cout << "The kind value must either be Ticket or BruinCard." << endl;
        return 1;
    }
    
    // Question 2
    cout << "Breakfast, Lunch or Dinner? ";
    getline(cin, meal);
    
    // Check for valid answer to question 2
    if(meal != "Breakfast" && meal != "Lunch" && meal != "Dinner") {
        cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
        return 1;
    }
    
    // Following questions asked only to customers using BruinCard
    if(kind == "BruinCard") {
        // Question 3
        cout << "Student or Staff? ";
        getline(cin, type);
    
        // Check for valid answer to question 3
        if(type != "Student" && type != "Staff") {
            cout << "The type value must either be Student or Staff." << endl;
            return 1;
        }
        
        // Last question only asked to student customers
        if(type == "Student") {
            // Question 4
            cout << "Resident? ";
            getline(cin, resident);
        
            // Check for valid answer to question 4
            if(resident != "Yes" && resident != "No") {
                cout << "The resident value must either be Yes or No." << endl;
                return 1;
            }
        }
    }
    
    // Price is calculated and stored in double price
    // Nested if else statements sort through Ticket/BruinCard, Breakfast/Lunch/Dinner, Student/Staff, and Resident/Non-Resident
    
    // Ticket
    if(kind == "Ticket") {
        if(meal == "Breakfast") {
            price = 12.50;
        }
        else if(meal == "Lunch") {
            price = 14.50;
        }
        // Dinner
        else {
            price = 17.00;
        }
    // BruinCard
    } else {
        // Staff
        if(type == "Staff") {
            if(meal == "Breakfast") {
                price = 11.25;
            }
            else if(meal == "Lunch") {
                price = 12.75;
            //Dinner
            }
            else {
                price = 14.75;
            }
        // Student
        } else {
            // Resident
            if(resident == "Yes") {
                if(meal == "Breakfast") {
                    price = 9.75;
                }
                else if(meal == "Lunch") {
                    price = 11.25;
                //Dinner
                }
                else {
                    price = 12.25;
                }
            // Non-Resident
            } else {
                if(meal == "Breakfast") {
                    price = 10.00;
                }
                else if(meal == "Lunch") {
                    price = 11.75;
                //Dinner
                }
                else {
                    price = 12.75;
                }
            }
        }
    }
    
    // Price of meal is outputted
    cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
    return 0;
}
