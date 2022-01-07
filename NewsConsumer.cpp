#include "NewsConsumer.h"
#include "CulturalNews.h"
#include "SportsNews.h"

NewsConsumer::NewsConsumer(const string& n) : name(n) {} //konstruktor: inicializálom a name változót, a vektor az osztály példányosításakor üres
NewsConsumer::~NewsConsumer() {
    /*mivel a fõprogramban semmi nincsen dinamikusan lefoglalva, ezért
    nem kell felszabadítani az inbox-ban levõ pointereket */
}
void NewsConsumer::receive(News* n) {
    inbox.push_back(n); //ha az adott fogyasztó kap egy hírt beleteszem a vektorba
}


/* a következõ függvény azért itt helyezkedik el mivel, ahol a NewConsumer függvényt
deklaráltam, ott a fordító még nem ismerte a teljes NewSoure osztályt, azon belül is a
regitsterConsumer függvényt*/
void NewsConsumer::registerToSource(NewsSource* s) { //mivel az objektum címét kapja a függvénynek pointert kell várni
    s->registerConsumer(this); //"beregisztrálom" a hírforrásba az adott fogyasztót, az objektumra mutató pointerrel (this)
}


/*a következõ három függvény szintén azért került külsõleg definiálásra, mivel felhasználja a
News osztály print függvényét, amit abban az esetben, ha az osztályon belül valósítom meg
szintén csak a print függvény forward deklarálásával tudott volna használni*/
void NewsConsumer::printInbox() {
    cout << "Inbox for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végigmegyek a fogyasztó postaládájában lévõ híreken
        i->print(); //kiíratom a tartalmukat
    }
    cout << "===" << endl;
}
void NewsConsumer::printCultural() {
    cout << "Cultural news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végignézem a fogyasztó postaládájában lévõ híreket
        CulturalNews* cultn = dynamic_cast<CulturalNews*>(i); //megnézem, hogy az adott hír kulturális hír-e
        if (cultn) { //ha sikerült a kasztolás, tehát eredménye nem nullptr, tehát az adott hír kulturális hír, tehát
            cultn->print(); //kiíratom a hír tartalmát
        }
    }
    cout << "===" << endl;
}
void NewsConsumer::printSports() {
    cout << "Sports news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //végignézem a fogyasztó postaládájában lévõ híreket
        SportsNews* sportn = dynamic_cast<SportsNews*>(i); //megnézem, hogy sporthír-e az adott hír
        if (sportn) { //ha sikerült a kasztolás, tehát eredménye nem nullptr, akkor az adott hír sprothír, tehát
            sportn->print(); //kiíratom a hír tartalmát
        }
    }
    cout << "===" << endl;
}
