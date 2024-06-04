#pragma once
#include<bits/stdc++.h>
#include<iostream>
#include "log.hpp"

using namespace std;


class ILogger{
public:
    ILogger(){}
    virtual ~ILogger() = 0;    
    virtual bool log(Log *obj) = 0;
};

ILogger::~ILogger() = default;