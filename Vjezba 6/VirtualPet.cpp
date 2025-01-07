#include "VirtualPet.h"
#include <iostream>
using namespace std;

VirtualPet::VirtualPet(string i, string v) : ime(i), vrsta(v), glad(5), sreca(5), budan(true) {}

void VirtualPet::jedi() 
{
    glad = max(glad - 2, 0);
    sreca++;
    cout << ime << " pojeo je i sada je manje gladan i sretniji!" << endl;
}

void VirtualPet::spavaj() 
{
    if (glad <= 4) 
    {
        budan = false;
        sreca += 2;
        glad++;
        cout << ime << " sada spava te je sretniji i malo gladniji." << endl;
    }
    else 
    {
        cout << ime << " gladan je i treba spavati!" << endl;
    }
}

void VirtualPet::igrajSe() 
{
    sreca += 2;
    glad++;
    cout << ime << " se igrao i sada je sretniji, ali gladniji!" << endl;
}

int VirtualPet::dohvatiSrecu() const 
{
    return sreca;
}

string VirtualPet::dohvatiIme() const
{
    return ime;
}

void VirtualPet::ispisStatusa() const 
{
    cout << "Ljubimac: " << ime << ", Vrsta: " << vrsta
        << ", Glad: " << glad << ", Sreca: " << sreca
        << ", Budan: " << (budan ? "Da" : "Ne") << endl;
}
