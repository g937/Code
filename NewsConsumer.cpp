#include "NewsConsumer.h"
#include "CulturalNews.h"
#include "SportsNews.h"

NewsConsumer::NewsConsumer(const string& n) : name(n) {} //konstruktor: inicializ�lom a name v�ltoz�t, a vektor az oszt�ly p�ld�nyos�t�sakor �res
NewsConsumer::~NewsConsumer() {
    /*mivel a f�programban semmi nincsen dinamikusan lefoglalva, ez�rt
    nem kell felszabad�tani az inbox-ban lev� pointereket */
}
void NewsConsumer::receive(News* n) {
    inbox.push_back(n); //ha az adott fogyaszt� kap egy h�rt beleteszem a vektorba
}


/* a k�vetkez� f�ggv�ny az�rt itt helyezkedik el mivel, ahol a NewConsumer f�ggv�nyt
deklar�ltam, ott a ford�t� m�g nem ismerte a teljes NewSoure oszt�lyt, azon bel�l is a
regitsterConsumer f�ggv�nyt*/
void NewsConsumer::registerToSource(NewsSource* s) { //mivel az objektum c�m�t kapja a f�ggv�nynek pointert kell v�rni
    s->registerConsumer(this); //"beregisztr�lom" a h�rforr�sba az adott fogyaszt�t, az objektumra mutat� pointerrel (this)
}


/*a k�vetkez� h�rom f�ggv�ny szint�n az�rt ker�lt k�ls�leg defini�l�sra, mivel felhaszn�lja a
News oszt�ly print f�ggv�ny�t, amit abban az esetben, ha az oszt�lyon bel�l val�s�tom meg
szint�n csak a print f�ggv�ny forward deklar�l�s�val tudott volna haszn�lni*/
void NewsConsumer::printInbox() {
    cout << "Inbox for consumer " << name << ":" << endl;
    for (auto i : inbox) { //v�gigmegyek a fogyaszt� postal�d�j�ban l�v� h�reken
        i->print(); //ki�ratom a tartalmukat
    }
    cout << "===" << endl;
}
void NewsConsumer::printCultural() {
    cout << "Cultural news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //v�gign�zem a fogyaszt� postal�d�j�ban l�v� h�reket
        CulturalNews* cultn = dynamic_cast<CulturalNews*>(i); //megn�zem, hogy az adott h�r kultur�lis h�r-e
        if (cultn) { //ha siker�lt a kasztol�s, teh�t eredm�nye nem nullptr, teh�t az adott h�r kultur�lis h�r, teh�t
            cultn->print(); //ki�ratom a h�r tartalm�t
        }
    }
    cout << "===" << endl;
}
void NewsConsumer::printSports() {
    cout << "Sports news for consumer " << name << ":" << endl;
    for (auto i : inbox) { //v�gign�zem a fogyaszt� postal�d�j�ban l�v� h�reket
        SportsNews* sportn = dynamic_cast<SportsNews*>(i); //megn�zem, hogy sporth�r-e az adott h�r
        if (sportn) { //ha siker�lt a kasztol�s, teh�t eredm�nye nem nullptr, akkor az adott h�r sproth�r, teh�t
            sportn->print(); //ki�ratom a h�r tartalm�t
        }
    }
    cout << "===" << endl;
}
