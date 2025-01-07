#include "Owner.h"
#include <iostream>
#include <random>
using namespace std;

Owner::Owner(string i) : ime(i) {}

void Owner::dodajLjubimca(const VirtualPet& ljubimac) 
{
    ljubimci.push_back(ljubimac);
}

void Owner::interakcijaSLjubimcima(int akcije) 
{
    vector<string> akcijeR = { "jedi", "igrajSe" }; 
    int indeks = 0; 

    for (int i = 0; i < akcije; ++i) 
    {
        for (auto& ljubimac : ljubimci) 
        {
            if (akcijeR[indeks] == "jedi") 
            {
                ljubimac.jedi();
            }
            else 
            {
                ljubimac.igrajSe();
            }
            indeks = (indeks + 1) % akcijeR.size(); 
        }
    }
}


VirtualPet Owner::najSretnijiLjubimac() const
{
    if (ljubimci.empty())
        throw runtime_error("Nema ljubimaca!");

    const VirtualPet* najsretniji = &ljubimci[0];
    for (const auto& ljubimac : ljubimci)
    {
        if (ljubimac.dohvatiSrecu() > najsretniji->dohvatiSrecu())
        {
            najsretniji = &ljubimac;
        }
    }
    return *najsretniji;
}


void Owner::ispisLjubimaca() const 
{
    cout << "Vlasnik: " << ime << endl;
    for (const auto& ljubimac : ljubimci) 
    {
        ljubimac.ispisStatusa();
    }
}
