#include <iostream>
#include <vector>
using namespace std;

void ukloni_element(vector<int>& vect, int indeks)
{
    if (indeks >= vect.size())
    {
        cout << "Preveliki indeks." << endl;
    }
    vect[indeks] = vect.back();
    vect.pop_back();
}

int main4()
{
    vector<int> vect{ 1,2,3,4 };

    ukloni_element(vect, 1);
    cout << "Uklonjen element sa prvom indeksa" << endl;

    cout << "Stanje;" << vect.size() << endl;

    return 0;
}