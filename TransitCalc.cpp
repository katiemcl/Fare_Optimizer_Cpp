/*
* TransitCalc.cpp
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "TransitCalc.h"
#include "math.h"
using namespace std;

double PRICES[3] = {2.75, 33.0, 127};     // regular prices
double REDUCED[3] = {1.35, 16.50, 63.50}; // reduced prices
const double DAYS[3] = {1, 7, 30};        // number of days per pass option

TransitCalc::TransitCalc(int singleDays, int numRides, bool discount){
    days = singleDays;
    rides = numRides;

    if(discount) {
        memcpy(PRICES, REDUCED, sizeof(PRICES));
    }
}

double TransitCalc::unlimited7Price() {
    double numWks = ceil(days / DAYS[1]); // round up to full 7 day
    double totalPrice = numWks * PRICES[1];

    // round to nearest cent
    double pricePer = round((totalPrice / (double) rides) * 100) / 100.0;
    return pricePer;

}

double* TransitCalc::getRidePrices(){
    double* pricePer = new double[sizeof(PRICES)];

    pricePer[0] = PRICES[0]; // single pay per ride
    pricePer[1] = unlimited7Price(); // per ride w/ 7 day pass
        
    double numTix = ceil(days / DAYS[2]); // round up to full 30 day 
    double totalPrice = numTix * PRICES[2]; // total price of all tix

    // round to nearest cent
    double priceEach = round((totalPrice / (double) rides) * 100) / 100.0; 
    pricePer[2] = priceEach;
        
    return pricePer;
}

void TransitCalc::getBestFare(){
    double* costs = getRidePrices();
    double minVal = min((min(costs[0], costs[1])), costs[2]);
    string pass[3]= {"Pay-per-ride", "7-day Unlimited", "30-day Unlimited"};
    int ind = 2;
    if(minVal == costs[1]) {
        ind = 1;
    } if(minVal == costs[0]) {
        ind = 0;
    }
    double cost = costs[ind];

    cout << "You should get the " << pass[ind] << " option at $" << costs[ind] << " per ride." << endl;
}

int main() {

    int days = 2;
    int rides = 5;
    bool disc = true;

    TransitCalc* test = new TransitCalc(days, rides, disc);

    double* prices = test->getRidePrices();

    // Print 1 day
    cout << "Price per ride with Pay-per-ride: $" << prices[0] << endl;

    // Print 7 day 
    cout << "Price per ride with 7-day Unlimited: $";
    cout << fixed;
    cout << setprecision(2);
    cout << test->unlimited7Price() << endl;

    // Print 30 day
    cout << "Price per ride with 30-day Unlimited: $" << prices[2] << endl;

    // Recommendation
    test->getBestFare();
}