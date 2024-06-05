#include<bits/stdc++.h>
#include<iostream>
#include "concrete-colors.hpp"
#include "concrete-shapes.hpp"
using namespace std;


int main(){
    
    Color *redColor = new RedColor();
    Color *greenColor = new GreenColor();

    Circle *redCircle = new Circle(redColor);
    Square *greenSquare = new Square(greenColor);    

    cout << redCircle->shine() << endl;
    cout << greenSquare->isOfColor() << endl;

}   