#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "actions_interface.hpp"
#include "vending_machine.hpp"

using namespace std;


class OutOfGumBall: public IStateActions{
public:
    VendingMachine *_state;

    OutOfGumBall(VendingMachine *state){
        _state = state;
    }

    void insertMoney(){
        cout<< "Can't insert money out of gumballs"<<endl;        
    }
    void ejectMoney(){
        cout<< "Can't insert money out of gumballs"<<endl;        
    }
    void turnCrank(){
        cout<< "Can't insert money out of gumballs"<<endl;        
    }
    void dispense(){
        cout<< "Can't insert money out of gumballs"<<endl;        
    }
};

class NoMoney: public IStateActions{
public:
    VendingMachine *_state;    

    NoMoney(VendingMachine *state){
        _state = state;
    }

    void insertMoney(){
        cout<< "Successfully money inserted"<<endl;        
        _state->setState(_state->getHasMoney());
    }
    void ejectMoney(){
        cout<< "Can't"<<endl;                   
    }
    void turnCrank(){
        cout<< "Can't turnCrank"<<endl;                
    }
    void dispense(){
         cout<< "Can't dispensed"<<endl;        
    }

};

class HasMoney: public IStateActions{
public:
    VendingMachine *_state;
    
    HasMoney(VendingMachine *state){
        _state = state;
    }

    void insertMoney(){
        cout<< "Can't insert already mony is present"<<endl;                
    }
    void ejectMoney(){
        cout<< "Successfully money Ejected"<<endl;           
        _state->setState(_state->getNoMoney());
    }
    void turnCrank(){
        cout<< "Successfully turnCrank"<<endl;        
        _state->setState(_state->getCandySold());
    }
    void dispense(){
         cout<< "Can't dispensed turn the crank!!"<<endl;        
    }
};

class CandySold: public IStateActions{
public:
    VendingMachine *_state;

    CandySold(VendingMachine *state){
        _state = state;
    }

    void insertMoney(){
        cout<< "Can't insert already mony is present"<<endl;                
    }
    void ejectMoney(){
        cout<< "Can't Ejected"<<endl;
    }
    void turnCrank(){
        cout<< "Can't turnCrank"<<endl;
    }
    void dispense(){
         if(_state->inventory > 0){
            _state->inventory = _state->inventory - 1;
            cout<<"Collect ball"<< endl;
         }

        if( _state->inventory > 0){
            _state->setState(_state->getNoMoney());
        }else{
            _state->setState(_state->getOutOfGumBall());
        }
    }

};