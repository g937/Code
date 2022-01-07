#include"News.h"

News::News(const string& h) : hir(h) {} //konstruktor: kezd��rt�ket adok a hir v�ltoz�nak
void News::print() {
    cout << hir << endl; //ki�ratom a h�r tartalm�t
}
News::~News() {} /*k�t okb�l virtu�lis: 1, a dynamic_cast-hoz kell legal�bb egy viru�lis
                   f�ggv�ny
                   2, (itt most ez l�nyegtelen) ha dinamikusan lenne l�trehozva
                   pl.: egy sporth�r, amit news t�pus� pointerrel hivatkozunk �s, ha ezzel a
                   pointerrel szabad�tjuk fel, akkor a gyerek oszt�ly destruktora is
                   megh�v�djon */