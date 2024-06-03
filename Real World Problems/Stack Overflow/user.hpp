#pragma once
#include<bits/stdc++.h>
using namespace std;


class User{
public:
    string id;
    int reputation;
    string name;

    User(string name){
        this->reputation = 0;
        this->name = name;
    }

    void setReputation(int newReputation){
        this->reputation = newReputation;
    }

    int getReputation(){
        return this->reputation;
    }

    string getUserId(){
        return this->id;
    }
    
};