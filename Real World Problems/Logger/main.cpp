#include<bits/stdc++.h>
#include<iostream>

#include "concrete-logger.hpp"
#include "logger.hpp"
#include "log-levels.hpp"
#include "log.hpp"

using namespace std;


int main(){
    Log *a = new Log(INFO, time(nullptr), "some random message from a");
    Log *b = new Log(INFO, time(nullptr), "some random message b");


    // DbLogger *dbLogger = new DbLogger(true);
    // ConsoleLogger *consoleLogger = new ConsoleLogger(true);
    vector<ILogger *> z;
    z.push_back(new DbLogger(true));
    z.push_back(new ConsoleLogger(true));
    IConfig *config = new IConfig(z);

    Logger *logger = new Logger(config, LogLevel::INFO);    

    logger->log(b);
    logger->log(a);

}