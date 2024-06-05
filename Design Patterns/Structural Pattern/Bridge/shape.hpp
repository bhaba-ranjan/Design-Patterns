#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "colors.hpp"
using namespace std;


class Shape{

protected:
    Color *color;
    string name;

public:
    Shape(){}
    virtual ~Shape()=0;
};

Shape::~Shape()=default;