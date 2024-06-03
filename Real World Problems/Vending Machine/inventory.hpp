#pragma once
#include<bits/stdc++.h>
#include<iostream>

using namespace std;


class Product{
public:
    string name;
    int quantity;

    Product(string name, string id){
        this->name = name;
    }    

    string getName() const {
        return name;
    }

    void setName(string value) {
        name = value;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int value) {
        quantity = value;
    }
    
};
    
class Inventory {
public:
    unordered_map<string, int>productQuantityMapper;

    bool addProduct(Product *product){        
        if(productQuantityMapper.find(product->name) == productQuantityMapper.end()){
            productQuantityMapper[product->name] = product->quantity;
            return true;
        }else{
            productQuantityMapper[product->name] = product->quantity;
            return true;
        }

        return false;
    }

    bool removeProduct(Product *product){
        if(productQuantityMapper.find(product->name) != productQuantityMapper.end()){
            productQuantityMapper.erase(product->name);
        }
    }

    
};
