#pragma once
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class IItem{
protected:
    string id;
    string name;
    int count;
    int price; // TODO: should be float
    virtual ~IItem() = 0;
};

IItem::~IItem() = default;


class Item: public IItem{
public:
    Item(string id, string name, int count){
        this->id = id;
        this->name = name;
        this->count = count;
    }

    int getCount(){
        return this->count;        
    }

    void setCount(int count){
        this->count = count;
    }
};
