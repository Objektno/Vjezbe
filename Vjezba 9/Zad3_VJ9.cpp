#include <iostream>
#include <algorithm>
#include <cctype> 
using namespace std;

void sortiraj(char* niz, size_t velicina) 
{
    sort(niz, niz + velicina, [](char a, char b) 
        {
        return tolower(a) < tolower(b);
        });
}

int main353() {
    char charNiz[] = "dCbA";
    size_t velicinaChar = sizeof(charNiz) - 1; 

    sortiraj(charNiz, velicinaChar);

    cout << "Sortirani char niz: " << charNiz << endl;

    return 0;
}
