#pragma once
#include <string>
#include <vector>
#include "News.h"
class NewsConsumer; //nem includoltam, mert k�l�nben k�rk�r�s hivatkoz�s lett volna, eloszor
			// include-oltam, de ugye problemak voltak

using namespace std;

class NewsSource {
    const string name; //h�rforr�s neve
    vector<NewsConsumer*> list_of_consumers; //a h�rforr�s fogyaszt�it tartalmaz� vektor
public:
    NewsSource(const string& name);
    void registerConsumer(NewsConsumer* c);
    void publishNews(News* n);
};