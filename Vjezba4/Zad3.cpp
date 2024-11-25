#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void obradiStringove() 
{
    vector<string> vektor; //DNL
    string unos;

    cout << "Unesi stringove (unesi 'okreni' za završetak):" << endl;
    while (true) 
    {
        getline(cin, unos);
        if (unos == "okreni") break;
        vektor.push_back(unos);
    }

    for (size_t i = 0; i < vektor.size(); ++i) 
    {
        reverse(vektor[i].begin(), vektor[i].end());
    }

    sort(vektor.begin(), vektor.end());

    cout << "Sortirani preokrenuti stringovi:" << endl;
    for (const auto& str : vektor) {
        cout << str << endl;
    }
}

int main8909() 
{
    obradiStringove();
    return 0;
}
