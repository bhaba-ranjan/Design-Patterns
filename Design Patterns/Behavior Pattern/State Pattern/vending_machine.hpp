#pragma once
#include<bits/stdc++.h>
#include "actions_interface.hpp"

using namespace std;

class VendingMachine{
public:
    IStateActions *noMoney;
    IStateActions *hasMoney;
    IStateActions *outOfGumBall;
    IStateActions *candySold;

    IStateActions *currentState;

    int inventory;

    VendingMachine(int capacity);

    void insertMoney();
    void ejectMoney();
    void turnCrank();
    void dispense();

    void setState(IStateActions *newState);

    IStateActions* getNoMoney();
    IStateActions* getHasMoney();
    IStateActions* getOutOfGumBall();
    IStateActions* getCandySold();
};