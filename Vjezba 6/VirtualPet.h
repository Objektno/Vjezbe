#pragma once

#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>
using namespace std;

class VirtualPet 
{
private:
    string ime;
    string vrsta;
    int glad;
    int sreca;
    bool budan;

public:
    VirtualPet(string i, string v);
    void jedi();
    void spavaj();
    void igrajSe();
    int dohvatiSrecu() const;
    string dohvatiIme() const;
    void ispisStatusa() const;

    bool operator==(const VirtualPet& drugi) const 
    {
        return ime == drugi.ime && vrsta == drugi.vrsta && sreca == drugi.sreca && glad == drugi.glad;
    }

    bool operator !=(const VirtualPet& drugi) const
    {
        return !(*this == drugi);
    }

    VirtualPet& operator =(const VirtualPet& drugi)
    {
        if (this != &drugi)
        {
            ime = drugi.ime;
            vrsta = drugi.vrsta;
            glad = drugi.glad;
            sreca = drugi.sreca;
            budan = drugi.budan;
        }
        return *this;
    }

    VirtualPet& operator++() 
    {
        glad++;
        sreca -= 5; 
        return *this;
    }

    bool operator<(const VirtualPet& drugi) const 
    {
        return sreca < drugi.sreca;
    }

    bool operator>(const VirtualPet& drugi) const 
    {
        return sreca > drugi.sreca;
    }

    bool operator<=(const VirtualPet& drugi) const 
    {
        return sreca <= drugi.sreca;
    }

    bool operator>=(const VirtualPet& drugi) const 
    {
        return sreca >= drugi.sreca;
    }

    friend ostream& operator<<(ostream& os, const VirtualPet& ljubimac) 
    {
        os << "Ime: " << ljubimac.ime << "\n"
            << "Vrsta: " << ljubimac.vrsta << "\n"
            << "Glad: " << ljubimac.glad << "\n"
            << "Sreća: " << ljubimac.sreca << "\n"
            << "Budan: " << (ljubimac.budan ? "Da" : "Ne");
        return os;
    }

};

#endif
