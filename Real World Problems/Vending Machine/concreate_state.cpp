#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "state_interface.hpp"
#include "vending-machine.hpp"

using namespace std;


class Ready: public IState{
private:
    VendingMachine *machine;

public:
    Ready(VendingMachine *machine){
        this->machine = machine;
    }

    bool selectProduct(string name){
        if(machine->inventory)
    }

    
};