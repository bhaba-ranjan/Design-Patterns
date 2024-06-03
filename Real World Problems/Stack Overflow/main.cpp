#include<bits/stdc++.h>
#include "stackoverflow.hpp"
#include<iostream>
#include<unordered_set>

using namespace std;


int main(){
    
    StackOverFlow* sof = StackOverFlow::getInstance();

    User *jon = new User("jhon");

    vector<string>tags;
    tags.push_back("t1");
    tags.push_back("t2");

    Question* q = new Question("qid", "desc question",tags);

    Answer a("aid", "desc answer");

    sof->postQuestion(q);

}