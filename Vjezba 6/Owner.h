#pragma once

#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include <string>
#include "VirtualPet.h"
using namespace std;

class Owner 
{
private:
    string ime;
    vector<VirtualPet> ljubimci;

public:
    Owner(string i);
    void dodajLjubimca(const VirtualPet& ljubimac);
    void interakcijaSLjubimcima(int akcije);
    VirtualPet najSretnijiLjubimac() const;
    void ispisLjubimaca() const;
};

#endif
