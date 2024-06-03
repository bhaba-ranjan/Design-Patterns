// math_operations.cpp
#pragma once
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class AbstractBeverage {        
    public:
        string description ="No description set";
        virtual string getDescription(){
            return description;
        }
        virtual double cost() = 0;
};