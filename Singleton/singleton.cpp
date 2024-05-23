#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Singleton{
    private:    

    static Singleton* _instance;     
    string _value;
    Singleton(string value) {
        _value = value;
    }

    public:

    // You should not be able to copy singleton;
    // delete the copy constructor;
    Singleton(Singleton &obj) = delete;

    static Singleton* getInstance(string value){
        if(_instance == nullptr){
            _instance  = new Singleton(value);
        }
        return _instance;
    } 

    void printValue(){
        cout<< "_value is:  "<< _value<< endl;
    }
};

Singleton* Singleton::_instance = nullptr;

int main(){
    Singleton* first_instance = Singleton::getInstance("first_instance");
    Singleton* second_instance = Singleton::getInstance("second_instance");

    first_instance->printValue();
    second_instance->printValue();
}