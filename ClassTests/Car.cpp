//
// Created by Dylan Shane on 10/4/17.
//

#include "Car.h"


Car::Car(std::string makeIn, std::string modelIn, int yearIn, int mileageIn, float askingPriceIn, float dealerCostIn){
    make = makeIn;
    model = modelIn;
    year = yearIn;
    mileage = mileageIn;
    askingPrice = askingPriceIn;
    dealerCost = dealerCostIn;
}

//methods
int Car::getMileage(){
    return mileage;
}

float Car::calcPotentialProfit(){
        return askingPrice - dealerCost;
};

std::string Car::toString(){

}
