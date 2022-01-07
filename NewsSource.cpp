#include"NewsSource.h"
#include "NewsConsumer.h"
#include<vector>
using namespace std;

NewsSource::NewsSource(const string& name) : name(name) {} //konstruktor: inicializálom a name változót, a vektor kezdetben nem tartalmaz fogyasztókat
void NewsSource::registerConsumer(NewsConsumer* c) {
    list_of_consumers.push_back(c); //beleteszem a kapott fogyasztót a hírforrás vektorába
}
void NewsSource::publishNews(News* n) { //ha megjelenik egy hír
    for (auto c : list_of_consumers) { //végigmegyek a fogyasztókon
        c->receive(n);  //és beleteszem a postaládájukba a hírt
    }
}