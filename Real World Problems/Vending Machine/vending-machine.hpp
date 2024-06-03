#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "item.hpp"
#include "maintianer.hpp"
#include "state_interface.hpp"
using namespace std;

class VendingMachine{

private:
    
    unordered_map<string, IMaintainer*> maintainers;
    IState *currentState;
    int totalBill;
public:

    bool placeOrder(string name, int quantity);
    bool uploadItems(vector<pair<IItem*, int> > items);
    void insertMoney(int money);
    void verifyMoney(int money, int total);
    void dispenseOrder(IItem *item, int quantity);
    IMaintainer* login(string userId, string passWord);

    void setState(IState* newState);
    IState* getState();
};
