# Publish-subscribe modell (Observer)
Used programming language: C++ 
Date: 14.05.2021.
Description:
A projekfeladat egy úgynevezett C++ design pattern (viselkedési minta) megvalósítása.
A fogyasztó (hírfogyasztó) egy metódusát meghívva (registerToSource(Source*)), ez a metódus gondoskodik arról, hogy a forrásban (hírforrásban) be legyen regisztrálva az adott fogyasztó. Ezt úgy tudja elérni, hogy meghívja az argumentumként kapott pointernek egy metódusát, amit nevezhetünk registerConsumer()-nek. Ennek átadja a fogyasztó önmagát (vagy önmagára egy hivatkozást), hogy el tudja tárolni a forrás, hogy ennek a fogyasztónak is kell frissítéseket küldenie. Innentől kezdve a cél, hogy a publishNews metódus az összes fogyasztónak eljuttassa az adott hírt.
