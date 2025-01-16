#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>       
#include <algorithm>  
#include <iterator>   

struct Point 
{
    double x, y;

    double udaljenostOdIshodista() const 
    {
        return std::sqrt(x * x + y * y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) 
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& p) 
    {
        is >> p.x >> p.y;
        return is;
    }
};

void obradiTocke(const std::string& nazivDatoteke, double udaljenost, const Point& novaTocka) 
{
    std::ifstream ulazniTok(nazivDatoteke);
    if (!ulazniTok.is_open()) 
    {
        std::cerr << "Greska pri otvaranju datoteke: " << nazivDatoteke << std::endl;
        return;
    }

    std::vector<Point> tocke((std::istream_iterator<Point>(ulazniTok)),
        std::istream_iterator<Point>());
    ulazniTok.close();

    std::sort(tocke.begin(), tocke.end(), [](const Point& a, const Point& b) 
        {
        return a.udaljenostOdIshodista() < b.udaljenostOdIshodista();
        });

    std::replace_if(tocke.begin(), tocke.end(), [udaljenost](const Point& p) 
        {
        return std::abs(p.udaljenostOdIshodista() - udaljenost) < 1e-6; 
        }, novaTocka);

    std::cout << "Obra?ene to?ke:" << std::endl;
    for (const auto& tocka : tocke) 
    {
        std::cout << tocka << std::endl;
    }
}

int main() 
{
    const std::string nazivDatoteke = "points.txt";
    const double udaljenost = 5.0; 
    const Point novaTocka = { 10.0, 10.0 }; 

    obradiTocke(nazivDatoteke, udaljenost, novaTocka);

    return 0;
}
