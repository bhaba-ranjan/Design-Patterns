#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "invoker.hpp"

using namespace std;


int main(){
    RemoteController *remote = new RemoteController();

    remote->offCommandPress(1);

    Light *light = new Light();
    Heater *heater = new Heater();

    CommandLightOn* commandLightOn = new CommandLightOn(light);
    CommandLightOff* commandLightOff = new CommandLightOff(light);

    CommandHeaterOn* commandHeaterOn = new CommandHeaterOn(heater);
    CommandHeaterOff* commandHeaterOff = new CommandHeaterOff(heater);

    remote->setCommand(0, commandLightOn, commandLightOff);
    remote->setCommand(1, commandHeaterOn, commandHeaterOff);

    remote->onCommandPress(0);
    remote->onCommandPress(1);

    remote->offCommandPress(0);
    remote->offCommandPress(1);
}