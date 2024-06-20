#pragma once

#include<bits/stdc++.h>
#include<iostream>

using namespace std;


class ICommand{
public:
    ICommand(){}
    virtual void execute()  = 0;
};


