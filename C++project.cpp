#include <iostream>
#include <string>
#include <vector>

using namespace std;

class News; //forward deklaráció
class NewsSource; //forward deklaráció


class NewsConsumer {
    string name;
    vector<News*> inbox;
public:
    NewsConsumer(const string& n) : name(n) {} //konstruktor: inicializálom a name változót, a vektor az osztály példányosításakor üres
    ~NewsConsumer() {
        /*mivel a főprogramban semmi nincsen dinamikusan lefoglalva, ezért
        nem kell felszabadítani az inbox-ban levő pointereket */
    }
    void receive(News* n) {
        inbox.push_back(n); //ha az adott fogyasztó kap egy hírt beleteszem a vektorba
    }
    void registerToSource(NewsSource* s);
    void printInbox();
    void printSports();
    void printCultural();
};

class NewsSource {
    const string name; //hírforrás neve
    vector<NewsConsumer*> list_of_consumers; //a hírforrás fogyasztóit tartalmazó vektor
public:
    NewsSource(const string& name) : name(name) {} //konstruktor: inicializálom a name változót, a vektor kezdetben nem tartalmaz fogyasztókat
    void registerConsumer(NewsConsumer* c) {
        list_of_consumers.push_back(c); //beleteszem a kapott fogyasztót a hírforrás vektorába
    }
    void publishNews(News* n) { //ha megjelenik egy hír
        for (auto c : list_of_consumers) { //végigmegyek a fogyasztókon
            c->receive(n);  //és beleteszem a postaládájukba a hírt
        }
    }
   
};
/* a következő függvény azért itt helyezkedik el mivel, ahol a NewConsumer függvényt 
deklaráltam, ott a fordító még nem ismerte a teljes NewSoure osztályt, azon belül is a
regitsterConsumer függvényt*/ 
void NewsConsumer::registerToSource(NewsSource* s) { //mivel az objektum címét kapja a függvénynek pointert kell várni
    s->registerConsumer(this); //"beregisztrálom" a hírforrásba az adott fogyasztót, az objektumra mutató pointerrel (this)
}

class News {
protected:
    string hir;
public:
    News(const string& h) : hir(h) {} //konstruktor: kezdőértéket adok a hir változónak
    void print() {
        cout << hir << endl; //kiíratom a hír tartalmát
    }
    virtual ~News() {} /*két okból virtuális: 1, a dynamic_cast-hoz kell legalább egy viruális
                       függvény
                       2, (itt most ez lényegtelen) ha dinamikusan lenne létrehozva
                       pl.: egy sporthír, amit news típusú pointerrel hivatkozunk és, ha ezzel a
                       pointerrel szabadítjuk fel, akkor a gyerek osztály destruktora is 
                       meghívódjon */
};


class CulturalNews : public News {
public:
    CulturalNews(const string& c) : News(c) {} //a szülő osztály konstruktorának meghívásával inicializálom a hir változót, különben fordítási hibát kapnánk
    ~CulturalNews() {}
};
class SportsNews : public News {
public:
    SportsNews(const string& s) : News(s) {} //a szülő osztály konstruktorának meghívásával inicializálom a hir változót, különben fordítási hibát kapnánk
    ~SportsNews() {}
};

/*a következő három függvény szintén azért került külsőleg definiálásra, mivel felhasználja a
News osztály print függvényét, amit abban az esetben, ha az osztályon belül valósítom meg
szintén csak a print függvény forward deklarálásával tudott volna használni*/
void NewsConsumer::printInbox() {
    cout << "Inbox for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végigmegyek a fogyasztó postaládájában lévő híreken
        i->print(); //kiíratom a tartalmukat
    }
    cout << "===" << endl;
}
void NewsConsumer::printCultural() {
    cout << "Cultural news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végignézem a fogyasztó postaládájában lévő híreket
        CulturalNews* cultn = dynamic_cast<CulturalNews*>(i); //megnézem, hogy az adott hír kulturális hír-e
        if (cultn) { //ha sikerült a kasztolás, tehát eredménye nem nullptr, tehát az adott hír kulturális hír, tehát
            cultn->print(); //kiíratom a hír tartalmát
        }
    }
    cout << "===" << endl;
}
void NewsConsumer::printSports() {
    cout << "Sports news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végignézem a fogyasztó postaládájában lévő híreket
        SportsNews* sportn = dynamic_cast<SportsNews*>(i); //megnézem, hogy sporthír-e az adott hír
        if (sportn) { //ha sikerült a kasztolás, tehát eredménye nem nullptr, akkor az adott hír sprothír, tehát
            sportn->print(); //kiíratom a hír tartalmát
        }
    }
    cout << "===" << endl;
}

int main()
{
        NewsSource ap("Associated Press");
        NewsSource nhh("Nemzeti Hirkozlesi Hatosag");

        NewsConsumer paul("Paul");
        NewsConsumer anna("Anna");

        paul.registerToSource(&ap);
        anna.registerToSource(&nhh);

        SportsNews n1("Dirk Abwernajthy wins 15th Grand Slam");
        SportsNews n2("Lionel Quasar scores hat trick");
        CulturalNews n3("No concerts at Carnegie Hall during lockdown");
        CulturalNews n4("Museum of Fine Arts reopens following renovations");

        ap.publishNews(&n1); ap.publishNews(&n3); ap.publishNews(&n4);
        nhh.publishNews(&n2); nhh.publishNews(&n3); nhh.publishNews(&n4);

        paul.printInbox();
        paul.printCultural();
        paul.printSports();
        std::cout << std::endl;

        anna.printInbox();
        anna.printCultural();
        anna.printSports();

        NewsSource ns1("News Source 1");
        NewsSource ns2("News Source 2");

        NewsConsumer dirk("Dirk");
        NewsConsumer blaise("Blaise");

        blaise.registerToSource(&ns1);
        dirk.registerToSource(&ns2);

        SportsNews nn1("sports for blaise");
        SportsNews nn2("sports for dirk");
        CulturalNews nn3("cultural news for blaise");
        CulturalNews nn4("cultural news for dirk");
        ns1.publishNews(&nn1); ns1.publishNews(&nn3);
        ns2.publishNews(&nn2); ns2.publishNews(&nn4);

        blaise.printInbox();
        blaise.printCultural();
        blaise.printSports();
        dirk.printInbox();
        dirk.printCultural();
        dirk.printSports(); 
}

