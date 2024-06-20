#pragma once

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Light{
public:
    Light(){}
    void on(){
        cout<< "light is on\n";
    }
    void off(){
        cout<< "light is off\n";
    }
};


class Heater{
public:
    Heater(){}

    void on(){
        cout<< "Heater is on\n";
    }

    void off(){
        cout<< "Heater is off\n";
    }    
};