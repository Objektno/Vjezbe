#include <iostream>
#include "VirtualPet.h"
#include "Owner.h"
#include "Food.h"

using namespace std;

int main() 
{
    Owner ana("Ana");
    ana.dodajLjubimca(VirtualPet("Rex", "Pas"));
    ana.dodajLjubimca(VirtualPet("Mimi", "Macka"));

    Owner marko("Marko");
    marko.dodajLjubimca(VirtualPet("Bunny", "Zec"));
    marko.dodajLjubimca(VirtualPet("Goldie", "Riba"));

    ana.interakcijaSLjubimcima(3);
    marko.interakcijaSLjubimcima(3);

    VirtualPet prvi = ana.najSretnijiLjubimac();
    VirtualPet drugi = marko.najSretnijiLjubimac();

    cout << "\nNajsretniji ljubimac Ane: " << prvi.dohvatiIme() << endl;
    cout << "Najsretniji ljubimac Marka: " << drugi.dohvatiIme() << endl;

    cout << "\nLjubimci Ane:" << endl;
    ana.ispisLjubimaca();

    cout << "\nLjubimci Marka:" << endl;
    marko.ispisLjubimaca();

    cout << "\nNastavak je 7.vjezba!" << endl;

    Food porcija1;
    Food porcija2;

    cout << "Trenutno dostupno porcija: " << Food::getCounter() << endl;

    Food::removeFood(); 
    cout << "\nNakon uklanjanja: " << Food::getCounter() << endl;

    if (prvi == drugi) 
    {
        cout << "jednaki" << endl;
    }
    else {
        cout << "razliciti" << endl;
    }

    cout << "\nPrije prefiksnog inkrementa: \n" << prvi << endl;
    ++prvi;
    cout << "Nakon prefiksnog inkrementa: \n" << prvi << endl;

    if (prvi > drugi) 
    {
        cout << prvi.dohvatiIme() << " je sretniji od " << drugi.dohvatiIme() << "." << endl;
    }
    else if (prvi < drugi) 
    {
        cout << drugi.dohvatiIme() << " je sretniji od " << prvi.dohvatiIme() << "." << endl;
    }
    else 
    {
        cout << prvi.dohvatiIme() << " i " << drugi.dohvatiIme() << " imaju jednaku razinu sreće." << endl;
    }

    return 0;
}
