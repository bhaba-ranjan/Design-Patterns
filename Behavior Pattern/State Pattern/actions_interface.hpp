#pragma once
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class IStateActions {
public:
    virtual void insertMoney() = 0;
    virtual void ejectMoney() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};