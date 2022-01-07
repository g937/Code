#include"News.h"

News::News(const string& h) : hir(h) {} //konstruktor: kezdõértéket adok a hir változónak
void News::print() {
    cout << hir << endl; //kiíratom a hír tartalmát
}
News::~News() {} /*két okból virtuális: 1, a dynamic_cast-hoz kell legalább egy viruális
                   függvény
                   2, (itt most ez lényegtelen) ha dinamikusan lenne létrehozva
                   pl.: egy sporthír, amit news típusú pointerrel hivatkozunk és, ha ezzel a
                   pointerrel szabadítjuk fel, akkor a gyerek osztály destruktora is
                   meghívódjon */