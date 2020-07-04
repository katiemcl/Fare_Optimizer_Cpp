// TransitCalc.cpp

#include <iostream>
#include "math.h"
#include "TransitCalc.h"
using namespace std;

TransitCalc::TransitCalc(int singleDays, int numRides, bool discount){
    double PRICES[3] = {2.75, 33.0, 127};
    double REDUCED[3] = {1.35, 16.50, 63.50};
    const double DAYS[3] = {1, 7, 30};

    days = singleDays;
    rides = numRides;

    if(discount) {
        PRICES[3] = REDUCED[3];
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
        
    double numTix = ceil(days / DAYS[2]); // hround up to full 30 day 
    double totalPrice = numTix * PRICES[2]; // total price of all tix

    // round to nearest cent
    double priceEach = round((totalPrice / (double) rides) * 100) / 100.0; 
    pricePer[2] = priceEach;

    printPricePer(pricePer);
        
    return pricePer;
}

void TransitCalc::printPricePer(double* array){
    for(int c = 0; c < sizeof(array); c++) {
        std::cout << array[c] << " " << std::endl;
    }
}

void TransitCalc::getBestFare(){
    double* costs = getRidePrices();
    double min = std::min((std::min(costs[0], costs[1])), costs[2]);
    std::string type[3]= {"Pay-per-ride ", "7-day Unlimited ", "30-day Unlimited "};
    int ind = 2;
    if(min == costs[1]) {
        ind = 1;
    } if(min == costs[0]) {
        ind = 0;
    }
    double cost = costs[ind];

    cout << "You should get the " << type[ind] << " option at $" << costs[ind] << " per ride." << endl;
}