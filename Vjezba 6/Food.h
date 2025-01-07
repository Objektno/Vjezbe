#pragma once

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
using namespace std;

class Food 
{
private:
    static int counter; 
public:
    Food();
    static void removeFood(); 
    static int getCounter(); 
};

#endif
