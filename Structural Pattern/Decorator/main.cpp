#include<bits/stdc++.h>
#include<iostream>
#include "condiments.cpp"
#include "concrete_beverage.cpp"
#include "beverage_abstract.cpp"
using namespace std;

int main(){
    AbstractBeverage *bev1 = new DarkRoasted();
    cout<< bev1->getDescription();    
    cout<< endl;
    
    AbstractBeverage *bev2 = new MediumRoasted();
    cout<< bev2->getDescription() << "  Cost is: "<< bev2->cost();    
    cout<< endl;

    
    bev2 = new WhippedCream(bev2);
    cout<< bev2->getDescription() << "  Cost is: "<< bev2->cost();    
    cout<< endl;

    bev2 = new Chocolate(bev2);
    cout<< bev2->getDescription() << "  Cost is: "<< bev2->cost();    
    cout<< endl;

    bev2 = new Cookie(bev2);
    cout<< bev2->getDescription() << "  Cost is: "<< bev2->cost();    
    cout<< endl;

}