#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "beverage_abstract.cpp"
using namespace std;

class DarkRoasted: public AbstractBeverage{
    public:
        DarkRoasted(){
            description = "DarkRoasted";
        }
        double cost(){
            return 1.0;
        }
};

class MediumRoasted: public AbstractBeverage{
    public:
        MediumRoasted(){
            description = "MediumRoasted";
        }
        double cost(){
            return 2.0;
        }
};