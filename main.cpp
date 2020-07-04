// main.cpp

#include <iostream>
#include <iomanip>
#include "TransitCalc.h"
using namespace std;

int main() {
    /**int days;
    int rides;
    int discount;

    cout << "Number of days? ";
    cin >> days;

    cout << "Number of rides? ";
    cin >> rides;

    cout << "Eligible for discount? (0/1 = f/t) ";
    cin >> discount;

    bool disc = (discount == 1); */

    // test 7-day unlimited calculator

    int days = 2;
    int rides = 5;
    bool disc = false;

    
    TransitCalc test = TransitCalc(days, rides, disc);
    cout << "Price per ride with 7-day Unlimited: ";
    cout << fixed;
    cout << setprecision(2);
    cout << test.unlimited7Price() << endl;

    test.getBestFare();

    // TODO fix typo in java

}