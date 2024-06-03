#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "state_interface.hpp"
#include "vending-machine.hpp"

using namespace std;


class IdleState: public IState{
private:
    VendingMachine *machine;

public:
    IdleState(VendingMachine *machine){
        this->machine = machine;
    }

    bool selectProduct(string name){
        if(machine->inventory->isAvailable(name)){
            machine->setSelectedProduct(name);
            machine->setState(machine->getReadyState());
            cout<< "product selected"<<endl;
            return true;
        }else{
            cout<< "this product can't be selected"<<endl;            
        }
        return false;
    }

    void insertMoney(int money){
        cout<< "first select a product"<<endl;
    }

    void dispenseOrder(){
        cout<< "first select a product"<<endl;
    }

    
};


class ReadyState: public IState{
private:
    VendingMachine *machine;

public:
    ReadyState(VendingMachine *machine){
        this->machine = machine;
    }

    bool selectProduct(string name){
        cout<< "Insert the money for the product you selected"<<endl;
    }

    void insertMoney(int money){
        int price = this->machine->inventory->getPrice(machine->selectedProduct);        
        
        if(money < price) {
            cout<< "Insufficient funds";
            return;
        }else if(money > price){            
            returnChange(money -price);
        }
        this->machine->setState(this->machine->getDispenseState());
    }

    void dispenseOrder(){
        cout<< "Insert the money for the product you selected"<<endl;
    }

    void returnChange(int money){
        cout<< "collect change"<< money << endl;
    }

    
};


class DispenseState: public IState{
private:
    VendingMachine *machine;

public:
    DispenseState(VendingMachine *machine){
        this->machine = machine;
    }

    bool selectProduct(string name){
        cout<< "Click Dispense"<<endl;
    }

    void insertMoney(int money){
        cout<< "Click Dispense"<<endl;
    }

    void dispenseOrder(){
        cout<< "collect your order"<< this->machine->selectedProduct<<endl;
        this->machine->inventory->removeProduct(this->machine->selectedProduct);
        this->machine->setState(this->machine->getIdleSate());
    }

    void returnChange(int money){
        cout<< "Click Dispense"<<endl;
    }
    
};