#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "logger-config.hpp"
#include "log-cmd-interface.hpp"
#include "log-levels.hpp"
#include "log.hpp"
using namespace std;


class Logger {
private:
    IConfig *differentLoggers;
    LogLevel logLevel;

public:
    Logger(IConfig *differentLoggers, LogLevel logLevel){
        this->differentLoggers = differentLoggers;
        this->logLevel = logLevel;
    }

    bool log(Log *log) const{
        vector<ILogger*> const destination =  differentLoggers->getLoggers();
        for(int i=0; i < destination.size(); i++){
            if(log->getLevel() <= this->logLevel) destination[i]->log(log);
        }
        cout<< endl;
    }  
};