#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype> 

void obradiRijeci(const std::string& nazivDatoteke, const std::string& podstring) 
{
    std::ifstream ulazniTok(nazivDatoteke);
    if (!ulazniTok.is_open()) 
    {
        std::cerr << "Greska pri otvaranju datoteke: " << nazivDatoteke << std::endl;
        return;
    }

    std::vector<std::string> rijeci((std::istream_iterator<std::string>(ulazniTok)),
        std::istream_iterator<std::string>());
    ulazniTok.close();

    rijeci.erase(std::remove_if(rijeci.begin(), rijeci.end(), [&podstring](const std::string& rijec) 
        {
        return rijec.find(podstring) != std::string::npos;
        }), rijeci.end());

    std::transform(rijeci.begin(), rijeci.end(), rijeci.begin(), [](std::string& rijec) 
        {
        std::transform(rijec.begin(), rijec.end(), rijec.begin(), ::toupper);
        return rijec;
        });

    std::cout << "Obra?ene rije?i:" << std::endl;
    for (const auto& rijec : rijeci) 
    {
        std::cout << rijec << std::endl;
    }
}

int main3235() 
{
    const std::string nazivDatoteke = "words.txt";
    const std::string podstring = "abc"; 

    obradiRijeci(nazivDatoteke, podstring);

    return 0;
}
