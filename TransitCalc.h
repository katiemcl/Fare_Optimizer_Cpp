// TransitCalc.h

#pragma once

#ifndef TRANSIT_CALC_H
#define TRANSIT_CALC_H

namespace std{
    class TransitCalc {
    public: 
        TransitCalc(int singleDays, int numRides, bool discount);
        
        double unlimited7Price();
        
        double* getRidePrices();
        
        void printPricePer(double* array);
        
        void getBestFare();

    private:
        int days;
        
        int rides;
        
        static double PRICES[3];
        
        static double REDUCED[3];
        
        static double DAYS[3];
};
}




#endif /* TRANSIT_CALC_H */