//
//  main.cpp
//  PRG-6-3-Winning-Division
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
/*
 Write a program that determines which of a company's four divisions (Northeast,
 Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It should
 include the following two functions, which are called by main:
 double getSales() is passed the name of a division. It asks the user for a division's
 quarterly sales figure, validates the input, then returns it. It should be called once for
 each division.
 void findHighest() is passed the four sales totals. It determines which is the largest
 and prints the name of the highest-grossing division, along with its sales figure.
 
 Input validation: Do not accept dollar amounts less than $0.00
 */

#include <iostream>
#include <iomanip>

using namespace std;

float getSales(string);
string findHighest(float, float, float, float);

int main()
{
    // Used to keep track of whether or not the regions sales have been entered or not
    bool NW = false,
         SW = false,
         NE = false,
         SE = false;
    
    float fltSalesNE,
          fltSalesSE,
          fltSalesNW,
          fltSalesSW;
    
    // Initialize sales figures
    fltSalesNE = 0.0f;
    fltSalesSE = 0.0f;
    fltSalesNW = 0.0f;
    fltSalesSW = 0.0f;
    
    string strDivision,
           strDivisionHighest;
    
    // Configure precision for dollar amount
    cout << setprecision(2) << fixed << showpoint;
    
    // Not a function because it makes function calls
    while(NW == false || SW == false || NE == false || SE == false)
    {
        cout << "Please select a division to enter sales for (NE, SE, NW, SW):\n";
        cin >> strDivision;
        
        if(strDivision == "ne" || strDivision == "NE" || strDivision == "Ne" || strDivision == "nE")
        {
            if(NE == false)
            {
                fltSalesNE = getSales(strDivision);
                NE = true;
            }
            else
            {
                cout << "You already entered this division's sales.\n";
            }
        }
        else if(strDivision == "se" || strDivision == "SE" || strDivision == "Se" || strDivision == "sE")
        {
            if(SE == false)
            {
                fltSalesSE = getSales(strDivision);
                SE = true;
            }
            else
            {
                cout << "You already entered this division's sales.\n";
            }
        }
        else if(strDivision == "nw" || strDivision == "NW" || strDivision == "Nw" || strDivision == "nW")
        {
            if(NW == false)
            {
                fltSalesNW = getSales(strDivision);
                NW = true;
            }
            else
            {
                cout << "You already entered this division's sales.\n";
            }
        }
        else if(strDivision == "sw" || strDivision == "SW" || strDivision == "Sw" || strDivision == "sW")
        {
            if(SW == false)
            {
                fltSalesSW = getSales(strDivision);
                SW = true;
            }
            else
            {
                cout << "You already entered this division's sales.\n";
            }
        }
        else
        {
            cout << "Please enter a valid division name (NW, SW, NE, SE):\n";
        }
    }
    
    strDivisionHighest = findHighest(fltSalesNE, fltSalesSE, fltSalesNW, fltSalesSW);
    
    cout << strDivisionHighest << " had the highest sales figures this year.";
    
    return 0;
}

// Used to return sales amount, do error-checking here
float getSales(string strDivision)
{
    float fltSalesAmount;
    
    cout << "Please enter division " << strDivision << "\'s sales:\n";
    cin >> fltSalesAmount;
    
    while(!cin || fltSalesAmount < 0 || fltSalesAmount > 1000000)
    {
        cout << "Please enter a dollar amount between\n"
        << "$0.00 and $1,000,000.00";
        cin.clear();
        cin.ignore();
        cin >> fltSalesAmount;
    }
    
    return fltSalesAmount;
    
}

// Compares sales numbers against one another to determine highest division's sales and return it
string findHighest(float fltSalesNE, float fltSalesSE, float fltSalesNW, float fltSalesSW)
{
    string strDivisionHighest;
    float fltHighestSalesFigure;
    
    if(fltSalesNE > fltSalesSE && fltSalesNE > fltSalesNW && fltSalesNE > fltSalesSW)
    {
        strDivisionHighest = "NE";
    }
    else if(fltSalesSE > fltSalesNE && fltSalesSE > fltSalesNW && fltSalesSE > fltSalesSW)
    {
        strDivisionHighest = "SE";
    }
    else if(fltSalesNW > fltSalesNE && fltSalesNW > fltSalesSE && fltSalesNW > fltSalesSW)
    {
        strDivisionHighest = "NW";
    }
    else if(fltSalesSW > fltSalesNE && fltSalesSW > fltSalesSE && fltSalesSW > fltSalesNW)
    {
        strDivisionHighest = "SW";
    }
    else
    {
        strDivisionHighest = "tie";
        cout << "ERROR: There was a tie.\n";
    }
    
    // Output final message to console
    if(strDivisionHighest == "NW")
    {
        fltHighestSalesFigure = fltSalesNW;
        cout << "NW had sales totalling $" << fltSalesNW << endl;
    }
    else if(strDivisionHighest == "SW")
    {
        fltHighestSalesFigure = fltSalesSW;
        cout << "SW had sales totalling $" << fltSalesSW << endl;
    }
    else if(strDivisionHighest == "NE")
    {
        fltHighestSalesFigure = fltSalesNE;
        cout << "NE had sales totalling $" << fltSalesNE << endl;
    }
    else if(strDivisionHighest == "SE")
    {
        fltHighestSalesFigure = fltSalesSE;
        cout << "SE had sales totalling $" << fltSalesSE << endl;
    }
    else
    {
        cout << "ERROR: Could not process highest sales figure.\n";
    }
    
    return strDivisionHighest;
}

