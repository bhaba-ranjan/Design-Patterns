#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "decorator_abstract.hpp"
using namespace std;

class WhippedCream: public CondimentDecorator{
    public:
        WhippedCream(AbstractBeverage *beverage){
            _beverage = beverage;
        }
        double cost (){
            return _beverage->cost()+0.01;
        }
        string getDescription(){
            return _beverage->getDescription()+" ,WhippedCream";
        }        
};


class Chocolate: public CondimentDecorator{
    public:
        Chocolate(AbstractBeverage *beverage){
            _beverage = beverage;
        }
        double cost (){
            return _beverage->cost()+0.01;
        }
        string getDescription(){
            return _beverage->getDescription()+" ,Chocolate";
        }        
};

class Cookie: public CondimentDecorator{
    public:
        Cookie(AbstractBeverage *beverage){
            _beverage = beverage;
        }
        double cost (){
            return _beverage->cost()+0.02;
        }
        string getDescription(){
            return _beverage->getDescription()+" ,Chocolate";
        }        
};