#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<iostream>

using namespace std;

class IComponent{
protected:
    string id;
    string desc;
    int upvote;
    // should be replaced with unordered_set (currently I do not have the library for set so going with map)
    unordered_set<string>upvoteList;    
    virtual ~IComponent() = 0;
};

IComponent::~IComponent() = default;


class Answer: public IComponent {
private:
    vector<string>upVotedUsersIds;  

public:
    Answer(string id, string desc){
        this->id = id;
        this->desc = desc;
        this->upvote = 0;
    }

    bool setVoteCount(int vote){
        this->upvote = vote;
    }

    int getVoteCount(){
        return this->upvote;
    }

};


class Question: public IComponent {

private:
    vector<string>tags;
    vector<Answer> answers;
    

public: 
    Question(string id, string desc, vector<string> tags){        
        this->id = id;
        this->desc = desc;
        this->tags = tags;
    }

    bool setVoteCount(int vote){
        this->upvote = vote;
    }

    int getVoteCount(){
        return this->upvote;
    }

    string getId(){
        return this->id;
    }

    bool addAnswers(Answer x){
        answers.push_back(x);
    }

    vector<string> getTags(){
        return this->tags;
    }

};