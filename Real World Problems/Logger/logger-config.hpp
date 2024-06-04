#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "concrete-logger.hpp" 

using namespace std;


class IConfig{
private:
    vector<ILogger *> logDestinations;

public:
    IConfig(vector<ILogger *> logDestinations){
        this->logDestinations = logDestinations;
    }
        
    vector<ILogger*> getLoggers() const {
        return logDestinations;
    }
};