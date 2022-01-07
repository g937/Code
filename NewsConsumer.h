#pragma once
#include"News.h"
#include "NewsSource.h"
#include <string>
#include <vector>

using namespace std;

class NewsConsumer {
    string name;
    vector<News*> inbox;
public:
    NewsConsumer(const string& n);
    ~NewsConsumer();
    void receive(News* n);
    void registerToSource(NewsSource* s);
    void printInbox();
    void printSports();
    void printCultural();
};