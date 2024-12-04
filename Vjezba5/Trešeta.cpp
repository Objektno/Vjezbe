#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class Karta 
{
    int broj;
    string zog;

public:
    Karta() 
    {
        broj = 0;       
        zog = "Prazno"; 
    }

    Karta(int b, const string& z) 
    {
        broj = b;
        zog = z;
    }

    int getBroj() const 
    {
        return broj;
    }

    string getZog() const 
    {
        return zog;
    }

    void ispisi() const 
    {
        cout << broj << " " << zog << endl;
    }
};

class Mac 
{
    vector<Karta> karte;

public:
    Mac() 
    {
        string zoga[] = { "Bastona", "Kupe", "Dinari", "Spade" };
        for (const auto& zog : zoga)
            for (int broj = 1; broj <= 10; ++broj)
                karte.emplace_back(broj, zog);
    }


    void promijesaj() 
    {
        shuffle(karte.begin(), karte.end(), random_device());
    }

    vector<Karta> podijeli(int brojKarata) 
    {
        vector<Karta> podijeljene(karte.end() - brojKarata, karte.end());
        karte.resize(karte.size() - brojKarata);
        return podijeljene;
    }
};

class Igrac 
{
    string ime;
    vector<Karta> karte;
    int bodovi;

public:
    Igrac(const string& i) : ime(i), bodovi(0) {}

    void setKarte(const vector<Karta>& noveKarte) 
    {
        karte = noveKarte;
    }

    void izracunajAkuzu() 
    {
        int brojaci[11] = { 0 };
        for (const auto& karta : karte) brojaci[karta.getBroj()]++;
        for (int broj : {1, 2, 3})
            if (brojaci[broj] >= 3) bodovi += 3;
    }

    void prikaziKarte() const 
    {
        cout << ime << " ima karte:";
        for (const auto& karta : karte)
            cout << " " << karta.getBroj() << " od " << karta.getZog();
        cout << endl;
    }

    void prikaziBodove() const 
    {
        cout << ime << " ima " << bodovi << " bodova iz akuze." << endl;
    }
};

int main() 
{
    int brojIgraca;
    cout << "Unesi broj igraca (2 ili 4): ";
    cin >> brojIgraca;

    if (brojIgraca != 2 && brojIgraca != 4)
    {
        cout << "Neispravan broj igraca! Igra podrzava samo 2 ili 4 igraca." << endl;
        return 1;
    }

    vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; ++i) 
    {
        string ime;
        cout << "Unesi ime igraca " << i + 1 << ": ";
        cin >> ime;
        igraci.emplace_back(ime);
    }

    Mac mac;
    mac.promijesaj();

    for (auto& igrac : igraci) 
    {
        igrac.setKarte(mac.podijeli(10));
        igrac.izracunajAkuzu();
    }

    cout << "\nRezultati:\n";
    for (const auto& igrac : igraci) 
    {
        igrac.prikaziKarte();
        igrac.prikaziBodove();
        cout << endl;
    }

    return 0;
}
