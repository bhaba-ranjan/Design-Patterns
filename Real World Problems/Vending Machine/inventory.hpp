#pragma once
#include<bits/stdc++.h>
#include<iostream>

using namespace std;


class Product{
public:
    string name;
    int quantity;
    int price;

    Product(string name, int quantity, int price){
        this->name = name;
        this->quantity = quantity;
        this->price = price;
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
    unordered_map<string, int>productPriceMapper;

    bool addProduct(Product *product){        
        if(productQuantityMapper.find(product->name) == productQuantityMapper.end()){
            productQuantityMapper[product->name] = product->quantity;
            productPriceMapper[product->name] = product->price;

            return true;
        }else{
            productQuantityMapper[product->name] = product->quantity;
            return true;
        }

        return false;
    }

    bool removeProduct(string name){
        productQuantityMapper[name] -= 1;
        if(productQuantityMapper[name] == 0) {
            productQuantityMapper.erase(name);
        }
        return true;
    }

    bool isAvailable(string name){
        if(productQuantityMapper.find(name) == productQuantityMapper.end()) return false;
        return productQuantityMapper[name] > 0;
    }

    int getPrice(string name){
        return productPriceMapper[name];
    }
    
};
