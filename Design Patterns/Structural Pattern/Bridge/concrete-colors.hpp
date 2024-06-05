
#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "colors.hpp"

using namespace std;

class GreenColor: public Color{

protected:
    string name;

public:
    GreenColor(){
        this->name = "Green";
    }
    string shine(){
        return "I'm shining Greenish";
    }
    string isOfColor(){
        return "My color is Green";
    }
};



class RedColor: public Color{

protected:
    string name;

public:
    RedColor(){
        this->name = "Red";
    }
    string shine(){
        return "I'm shining reddish";
    }
    string isOfColor(){
        return "My color is red";
    }
};

