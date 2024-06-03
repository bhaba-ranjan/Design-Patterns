#include<bits/stdc++.h>
#include<iostream>
#include "vending-machine.cpp"
#include "inventory.hpp"
using namespace std;


int main(){
    VendingMachine *vendingMachine = new VendingMachine();
    Product* product = new Product("coke", 2, 1);

    vendingMachine->inventory->addProduct(product);

    vendingMachine->selectProduct("coke");
    vendingMachine->insertMoney(2);
    vendingMachine->dispenseOrder();
    cout<< endl<< endl;

    vendingMachine->selectProduct("coke");
    cout<< "invalid request dispense after selection result:: ";
    vendingMachine->dispenseOrder();
    vendingMachine->insertMoney(1);
    vendingMachine->dispenseOrder();
    cout<< endl<< endl;

    vendingMachine->selectProduct("coke");
    vendingMachine->insertMoney(2);
    vendingMachine->dispenseOrder();
}