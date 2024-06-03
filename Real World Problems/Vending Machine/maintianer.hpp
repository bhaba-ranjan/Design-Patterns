#pragma once
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class IMaintainer{
protected:
    string id;
    string name;
    virtual ~IMaintainer() = 0;
};

IMaintainer::~IMaintainer() = default;

class Maintainer: IMaintainer{
public:
    Maintainer(string id, string name){
        this->id = id;
        this->name = name;
    }
};