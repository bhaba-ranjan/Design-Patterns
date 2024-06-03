#pragma once
#include<bits/stdc++.h>
#include "vending_machine.hpp"
#include "concrete_state.hpp"
using namespace std;


VendingMachine::VendingMachine(int capacity){
    inventory = capacity;

    noMoney = new NoMoney(this);
    hasMoney = new HasMoney(this);
    outOfGumBall = new OutOfGumBall(this);
    candySold = new CandySold(this);

    currentState = noMoney;
}

void VendingMachine::insertMoney(){
    currentState->insertMoney();
}

void VendingMachine::ejectMoney(){
    currentState->ejectMoney();
}

void VendingMachine::turnCrank(){
    currentState->turnCrank();
}

void VendingMachine::dispense(){
    currentState->dispense();
}


void VendingMachine::setState(IStateActions *newState){
    currentState = newState;
}

IStateActions* VendingMachine::getNoMoney(){
    return noMoney;
}

IStateActions* VendingMachine::getHasMoney(){
    return hasMoney;
}

IStateActions* VendingMachine::getOutOfGumBall(){
    return outOfGumBall;
}

IStateActions* VendingMachine::getCandySold(){
    return candySold;
}


