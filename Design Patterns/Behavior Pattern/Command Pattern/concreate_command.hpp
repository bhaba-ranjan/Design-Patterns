#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "receiver.hpp"
#include "command_interface.hpp"
using namespace std;


class CommandLightOn: public ICommand {
public:
    Light *light;

    CommandLightOn(Light *light) {
        this->light = light;
    }

    void execute(){
        this->light->on();
    }
    
    void undo(){
        this->light->off();
    }
};

class CommandLightOff: public ICommand {
public:
    Light *light;

    CommandLightOff(Light *light) {
        this->light = light;
    }

    void execute(){
        this->light->off();
    }

    void undo(){
        this->light->on();
    }
};


class CommandHeaterOn: public ICommand {
public:
    Heater *heater;

    CommandHeaterOn(Heater *heater) {
        this->heater = heater;
    }

    void execute(){
        this->heater->on();
    }
    
    void undo(){
        this->heater->off();
    }
};

class CommandHeaterOff: public ICommand {
public:
    Heater *heater;

    CommandHeaterOff(Heater *heater) {
        this->heater = heater;
    }

    void execute(){
        this->heater->off();
    }

    void undo(){
        this->heater->on();
    }
};


class NoCommand: public ICommand{
public:
    void execute(){
        cout<<"no commands has been assigned yet\n";
    }
};