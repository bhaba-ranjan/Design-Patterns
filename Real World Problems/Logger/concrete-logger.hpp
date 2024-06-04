#pragma once

#include<bits/stdc++.h>
#include<iostream>

#include "log-cmd-interface.hpp" 
#include "log.hpp"

using namespace std;


class DbLogger: public ILogger{
private:
    bool canBeADebLoggerConfig;

public:

    DbLogger(bool canBeADebLoggerConfig){
        this->canBeADebLoggerConfig = canBeADebLoggerConfig;
    }

    bool log(Log *obj){
        cout<<"from DbLogger:: ";
        cout<< obj->getLevel() << " "<< obj->getTimestamp() << " "<< obj->getMessage();
        cout << endl;
    }

};



class FileLogger: public ILogger{
private:
    bool canBeAFileLoggerConfig;

public:

    FileLogger(bool canBeAFileLoggerConfig) {
        this->canBeAFileLoggerConfig = canBeAFileLoggerConfig;
    }

    bool log(Log *obj){
        cout<<"from FileLogger:: ";
        cout<< obj->getLevel() << " "<< obj->getTimestamp() << " "<<obj->getMessage();
        cout << endl;
    }

}; 



class ConsoleLogger: public ILogger{
private:
    bool canBeAConsoleLoggerConfig;

public:

    ConsoleLogger(bool canBeAConsoleLoggerConfig) {
        this->canBeAConsoleLoggerConfig = canBeAConsoleLoggerConfig;
    }

    bool log(Log *obj) {
        cout<<"from ConsoleLogger:: ";
        cout<< obj->getLevel() << " "<< obj->getTimestamp() << " "<< obj->getMessage();
        cout << endl;
    }

}; 