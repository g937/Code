#pragma once
#include <string>
#include <vector>
#include "News.h"
class NewsConsumer; //nem includoltam, mert különben körkörös hivatkozás lett volna, eloszor
			// include-oltam, de ugye problemak voltak

using namespace std;

class NewsSource {
    const string name; //hírforrás neve
    vector<NewsConsumer*> list_of_consumers; //a hírforrás fogyasztóit tartalmazó vektor
public:
    NewsSource(const string& name);
    void registerConsumer(NewsConsumer* c);
    void publishNews(News* n);
};