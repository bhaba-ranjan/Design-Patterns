#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "item.hpp"
#include "maintianer.hpp"

using namespace std;

class IState {    
public: 
    virtual bool selectProduct(string name) =0;    
    virtual void insertMoney(int money)= 0;    
    virtual void dispenseOrder() = 0;   
};