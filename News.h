#pragma once
#include<iostream>
using  namespace std;

class News {
protected:
    string hir;
public:
    News(const string& h);
    void print();
    virtual ~News();
};
