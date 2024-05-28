#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "beverage_abstract.cpp"
using namespace std;

class CondimentDecorator: public AbstractBeverage{        
    public: 
        AbstractBeverage *_beverage;
        virtual string getDescription() {
            return _beverage->getDescription();
        };
};