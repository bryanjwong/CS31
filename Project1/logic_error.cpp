//
//  main.cpp
//  CS31 Project 1
//
//  Edited by Bryan Wong on 1/7/19.
// Code for Project 1
// Modified to create logic error
// Congress results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
    int republicanSeats;
    int democraticSeats;
    int independentSeats;
    
    cout << "How many seats are held by Democrats? ";
    cin >> democraticSeats;
    cout << "How many seats are held by Republicans? ";
    cin >> republicanSeats;
    cout << "How many seats are held by Independents? ";
    cin >> independentSeats;
    
    // A logic error is introduced here to not include Republican votes in the total
    // count of votes. This will cause the percentage of votes reported to be
    // incorrect, resulting in reported values that are greater than actual.
    int total = democraticSeats + independentSeats;
    
    double pctRep = 100.0 * republicanSeats / total;
    double pctDem = 100.0 * democraticSeats / total;
    // Another logic error here results in a reported percentage of Independent voters
    // that is 10 times the actual percent.
    double pctInd = 1000.0 * independentSeats / total;
    
    cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
    cout.precision(1);
    cout << endl << endl;
    cout << pctRep << "% Republicans" << endl;
    cout << pctDem << "% Democrats" << endl;
    cout << pctInd  << "% Independents" << endl;
    
    if (pctRep > pctDem)
    {
        cout << "Looks like control goes to the Republicans." << endl;
        
    }
    else
    {
        cout << "Looks like control goes to the Democrats." << endl;
        
    }
    return(0);
    
}


