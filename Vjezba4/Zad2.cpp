#include <iostream>
#include <string>

using namespace std;

string urediRecenicu(const string& recenica) 
{
    string rezultat;

    for (size_t i = 0; i < recenica.length(); ++i) 
    {
        char znak = recenica[i];

        if (znak == ' ' && (i + 1 < recenica.length()) &&
            (recenica[i + 1] == ',' || recenica[i + 1] == '.' || recenica[i + 1] == ';' ||
                recenica[i + 1] == ':' || recenica[i + 1] == '!' || recenica[i + 1] == '?')) 
        {
            continue;
        }

        if (znak == ',' || znak == '.' || znak == ';' || znak == ':' || znak == '!' || znak == '?') 
        {
            rezultat += znak;
            while (i + 1 < recenica.length() && recenica[i + 1] == ' ') 
            {
                i++;
            }
            rezultat += ' ';
        }
        else 
        {
            rezultat += znak;
        }
    }

    return rezultat;
}

int main2354235() 
{
    string recenica = "Ja bih ,ako ikako mogu ,  ovu recenicu napisala ispravno  .";
    string ispravnaRecenica = urediRecenicu(recenica);

    cout << "Ispravna recenica: " << ispravnaRecenica << endl;

    return 0;
}
