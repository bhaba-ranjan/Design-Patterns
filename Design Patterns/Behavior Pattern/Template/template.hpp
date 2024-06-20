#pragma once

#include<bits/stdc++.h>
#include<iostream>

using namespace std;


/**
 * Common steps to make tea/coffee
 * 
 * - boil water (same)
 * - add coffee, add tea (differ) [addNecessaryPowders]
 * - pour into the cup (same)
 * - add sugar and milk(for coffee), add lemon(for tea)  -> (differ) [addCondiments]
 * - create an abstract class with a frame framework and override the DIFFER methods in the subclasses.
 * 
*/

class BeverageMaker {
public:

    BeverageMaker(){}
    // The following is the TEMPLATE method
    // defines a frame work and delegates the differ logic to be defined in subclass
    void makeBeverage() {
        this->boilWater();
        this->addNecessaryPowders(); // differ -> propagated to subclass
        this->pourIntoTheCup();
        this->addCondiments(); // differ -> propagated to subclass
    }

    void boilWater() {
        cout<< "boiling water"<< endl;
    }

    void pourIntoTheCup() {
        cout<< "pouring into the cup"<< endl;
    }

    virtual void addNecessaryPowders() = 0;
    virtual void addCondiments() = 0;
};



class Tea: public BeverageMaker {
public:
    
    Tea(){}

    void addNecessaryPowders() override {
        cout<< "Adding Tea Bags."<< endl;
    }

    virtual void addCondiments() override {
        cout<< "Adding lemon."<<endl;
    }
};

class Coffee: public BeverageMaker {
public:
    
    Coffee(){}

    void addNecessaryPowders() override {
        cout<< "Adding COFFEE liquid."<< endl;
    }

    void addCondiments() override {
        cout<< "Adding sugar and milk."<<endl;
    }
};