#pragma once

#include<bits/stdc++.h>
#include<iostream>

#include "log-levels.hpp" 

using namespace std;



class Log {

private:
    LogLevel  level;
    time_t timestamp;
    string message;

public:

    Log(LogLevel level, time_t timestamp, string message){
        this->level = level;
        this->timestamp = timestamp;
        this->message = message;
    }

    LogLevel getLevel() const {
        return level;
    }

    time_t getTimestamp() const {
        return timestamp;
    }


    string getMessage() const {
        return message;
    }
};

