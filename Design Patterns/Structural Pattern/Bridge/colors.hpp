#pragma once

#include<bits/stdc++.h>
#include<iostream>

using namespace std;


class Color{

public:
    Color(){}
    virtual ~Color()=0;
    virtual string shine() = 0;
    virtual string isOfColor() = 0;
    
};

Color::~Color() = default;