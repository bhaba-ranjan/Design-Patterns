#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "vending-machine.hpp"
#include "inventory.hpp"
#include "concreate_state.cpp"
using namespace std;


VendingMachine::VendingMachine(){
    readyState = new ReadyState(this);
    idleState = new IdleState(this);
    dispenseState = new DispenseState(this);
    inventory = new Inventory();

    currentState = idleState;
}

void VendingMachine::selectProduct(string name){
    this->currentState->selectProduct(name);
}    

void VendingMachine::insertMoney(int money){
    this->currentState->insertMoney(money);
}    

void VendingMachine::dispenseOrder(){
    this->currentState->dispenseOrder();
}    

void VendingMachine::setState(IState* newState){
    this->currentState = newState;
}

void VendingMachine::setSelectedProduct(string name){
    this->selectedProduct = name;
}

IState* VendingMachine::getReadyState() const {
    return readyState;
}

IState* VendingMachine::getIdleSate() const {
    return idleState;
}


IState* VendingMachine::getDispenseState() const {
    return dispenseState;
}

// class VendingMachine{

// private:

//     IState *currentState;
//     IState *readyState;
//     IState *idleState;
//     IState *dispenseState;

// public:

//     Inventory *inventory;
//     string selectedProduct;
    
//     void selectProduct(string name){
//         this->currentState->selectProduct(name);
//     }    
//     void insertMoney(int money){
//         this->currentState->insertMoney(money);
//     }    
//     void dispenseOrder(){
//         this->currentState->dispenseOrder();
//     }    

//     void setState(IState* newState){
//         this->currentState = newState;
//     }

//     void setSelectedProduct(string name){
//         this->selectedProduct = name;
//     }
    

//     IState* getReadyState() const {
//         return readyState;
//     }

//     IState* getIdleSate() const {
//         return idleState;
//     }

//     IState* getIdleSate() const {
//         return idleState;
//     }

//     IState* getDispenseState() const {
//         return dispenseState;
//     }


// };