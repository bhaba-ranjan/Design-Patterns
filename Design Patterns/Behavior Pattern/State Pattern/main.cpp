#include <iostream>
#include <bits/stdc++.h>
#include "veding_machine.cpp"
using namespace std;


int main(){

    VendingMachine X(1);

    X.ejectMoney();
    X.dispense();
    X.insertMoney();
    X.turnCrank();
    X.dispense();
    X.insertMoney();

}



