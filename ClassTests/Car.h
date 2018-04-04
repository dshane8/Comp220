//
// Created by Dylan Shane on 10/4/17.
//

#ifndef CLASSTESTS_CAR_H
#define CLASSTESTS_CAR_H


class Car {
    //data members
private:
    std::string make;
    std::string model;
    int year;
    int mileage;
    float askingPrice;
    float dealerCost;

    //constructor
public:
    Car(std::string makeIn, std::string modelIn, int yearIn, int mileageIn, float askingPriceIn, float dealerCostIn);

    //methods
    std::string toString();
    int getMileage();
    float calcPotentialProfit;


};


#endif //CLASSTESTS_CAR_H
