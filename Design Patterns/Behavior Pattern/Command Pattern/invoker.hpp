#pragma once

#include<bits/stdc++.h>
#include<iostream>
#include "concreate_command.hpp"
using namespace std;

class RemoteController {
public:
    vector<ICommand*> onCommandSlots;
    vector<ICommand*> offCommandSlots;

    RemoteController(){
        onCommandSlots.assign(2, new NoCommand());                
        offCommandSlots.assign(2, new NoCommand());                
    }

    void setCommand(int slot, ICommand* on, ICommand* off){
        onCommandSlots[slot] = on;
        offCommandSlots[slot] = off;
    }

    void onCommandPress(int slot){
        onCommandSlots[slot]->execute();

    }
    
    void offCommandPress(int slot){
        offCommandSlots[slot]->execute();
    }
};
