#include"NewsSource.h"
#include "NewsConsumer.h"
#include<vector>
using namespace std;

NewsSource::NewsSource(const string& name) : name(name) {} //konstruktor: inicializ�lom a name v�ltoz�t, a vektor kezdetben nem tartalmaz fogyaszt�kat
void NewsSource::registerConsumer(NewsConsumer* c) {
    list_of_consumers.push_back(c); //beleteszem a kapott fogyaszt�t a h�rforr�s vektor�ba
}
void NewsSource::publishNews(News* n) { //ha megjelenik egy h�r
    for (auto c : list_of_consumers) { //v�gigmegyek a fogyaszt�kon
        c->receive(n);  //�s beleteszem a postal�d�jukba a h�rt
    }
}