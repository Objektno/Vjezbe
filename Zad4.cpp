#include <iostream>
#include <string>

using namespace std;

string prevodiNaPigLatin(const string& recenica) 
{
    string rijec, rezultat;
    string samoglasnici = "aeiouAEIOU";

    for (char c : recenica) 
    {
        if (c == ' ') 
        {
            if (rijec.length() > 0 && (samoglasnici.find(rijec[0]) < 5 || samoglasnici.find(rijec[0]) > 4)) 
            {
                rijec += "hay";
            }
            else if (rijec.length() > 0) 
            {
                size_t i = 0;
                while (i < rijec.length() && samoglasnici.find(rijec[i]) >= 5) 
                {
                    i++;
                }
                rijec = rijec.substr(i) + rijec.substr(0, i) + "ay";
            }
            rezultat += rijec + " ";
            rijec = "";
        }
        else 
        {
            rijec += c;
        }
    }

    return rezultat;
}

int main234() 
{
    string recenica = "What time is it?";
    cout << prevodiNaPigLatin(recenica) << endl;
    return 0;
}
