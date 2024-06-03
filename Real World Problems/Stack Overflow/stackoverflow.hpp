#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include "user.hpp"
#include "question.hpp"
#include<iostream>

using namespace std;


class StackOverFlow{
private:
    static StackOverFlow *_stackOverFlow;
    static mutex _mutex;

    unordered_map<string, pair<string, User*> > members;
    unordered_map<string, Question*> questions;
    unordered_map<string, vector<Question*> > catalogByTag;
    StackOverFlow(){}

public:

    static StackOverFlow* getInstance(){
        _mutex.lock();
        if(_stackOverFlow == nullptr){
            _stackOverFlow = new StackOverFlow();
        }
        _mutex.unlock();
        return _stackOverFlow;
    }


    string registerMember(User *user, string username, string password){
        if(members.find(username) != members.end()) return "user name already exists";
        members[username] = make_pair(password, user);
        return "registration successful";
    }

    User* login(string username, string password){
        if(members.find(username) == members.end()) return nullptr;
        if(members[username].first != password) return nullptr;

        return members[username].second;
    }

    bool postQuestion(Question *question){        
        this->questions[question->getId()] = question;
        indexIntoCatalog(question);
        return true;
    }

    bool postAnswer(Answer answer, Question question){
        question.addAnswers(answer);
    }

    void indexIntoCatalog(Question* question){
        for(string tag: question->getTags()){
            catalogByTag[tag].push_back(question);
        }
    }
    
    vector<Question*> search(string keyword){
        // search int the catalog
        return catalogByTag[keyword];
    }
    

};

StackOverFlow* StackOverFlow::_stackOverFlow = nullptr;
mutex StackOverFlow::_mutex;