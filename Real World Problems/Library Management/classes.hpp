#pragma once

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

enum bookStatus{
    AVAILABLE, BORROWED, NOT_SERVING
};


class Book {
public:
    string id;
    string authors;
    string title;
    string name;
    bookStatus status;
    virtual ~Book() = 0;
};

Book::~Book() = default;


class BookItem: Book{
public:
    ~BookItem() = default;
    void setStatus(bookStatus status){
        this->status = status;
    }
};


class Library: public BookItem{
private:
    unordered_map<string, BookItem>books;

};