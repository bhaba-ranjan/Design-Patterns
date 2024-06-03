#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "item.hpp"
#include "maintianer.hpp"
#include "state_interface.hpp"
#include "inventory.hpp"
using namespace std;

class VendingMachine{

private:
        
    IState *currentState;
    IState *readyState;
    IState *idleState;
    IState *dispenseState;

public:
    VendingMachine();

    Inventory *inventory;
    string selectedProduct;

    void selectProduct(string name);    
    void insertMoney(int money);    
    void dispenseOrder();    

    void setState(IState* newState);
    void setSelectedProduct(string name);
    

    IState* getReadyState() const;

    IState* getIdleSate() const;

    IState* getDispenseState() const;
};
