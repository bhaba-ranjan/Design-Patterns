#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "item.hpp"
#include "maintianer.hpp"

using namespace std;

class IState {    
public: 
    virtual bool selectProduct(string name) = 0;
    virtual bool uploadItems(vector<pair<IItem*, int> > items) = 0;
    virtual void insertMoney(int money) = 0;
    virtual void verifyMoney(int money, int total) = 0;
    virtual void dispenseOrder(IItem *item, int quantity) = 0;
    virtual IMaintainer* login(string userId, string passWord) = 0;
};