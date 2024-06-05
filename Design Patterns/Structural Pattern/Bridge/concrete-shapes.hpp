#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "shape.hpp"

using namespace std;


class Circle: public Shape{

public:
    Circle(Color *color){
        this->name = "Circle";
        this->color = color;
    }

    string shine(){
        return this->color->shine();
    }

    string isOfColor(){ 
        return this->color->isOfColor();
    }

    string getName() const {
        return this->name;
    }
    
};


class Square: public Shape{

public:
    Square(Color *color){
        this->name = "Square";
        this->color = color;
    }

    string shine(){
        return this->color->shine();
    }

    string isOfColor(){ 
        return this->color->isOfColor();
    }

        string getName() const {
        return this->name;
    }

};