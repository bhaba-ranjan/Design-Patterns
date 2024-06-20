#include<bits/stdc++.h>
#include<iostream>
#include "template.hpp"

using namespace std;


int main(){
    BeverageMaker *coffee = new Coffee();
    BeverageMaker *tea = new Tea();

    coffee->makeBeverage();

    cout<< endl;
    
    tea->makeBeverage();
}