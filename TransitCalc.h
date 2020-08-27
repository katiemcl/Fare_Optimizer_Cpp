// TransitCalc.h

// #include <iostream>
#pragma once

#ifndef TRANSIT_CALC_H
#define TRANSIT_CALC_H

namespace std{
    class TransitCalc {
    
    public: 
        // intialize variables for number days, rides, and if eligible for discount
        TransitCalc(int singleDays, int numRides, bool discount);
        
        // returns price per ride with 7 day unlimited option
        double unlimited7Price();
        
        // returns double array of the price/ride per each fare option
        double* getRidePrices();
        
        // prints recommendation ticket type and price
        void getBestFare();
    
    private:
        int days; // number of days using transit

        int rides; // number of rides using transit

};
}


#endif /* TRANSIT_CALC_H */