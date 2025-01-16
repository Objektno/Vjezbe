#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Skup 
{
private:
    vector<T> elementi; 

public:
  
    void dodaj(const T& element) 
    {
        elementi.push_back(element);
    }

 
    void izbaci(const T& element) 
    {
        auto it = find(elementi.begin(), elementi.end(), element);
        if (it != elementi.end()) 
        {
            elementi.erase(it);
        }
    }

  
    void ispisi() const 
    {
        std::cout << "{ ";
        for (const auto& el : elementi) 
        {
            cout << el << " ";
        }
        cout << "}" << endl;
    }
};

int main2342() {
    Skup<int> intSkup;
    intSkup.dodaj(5);
    intSkup.dodaj(10);
    intSkup.dodaj(5); 
    intSkup.ispisi();

    intSkup.izbaci(5); 
    intSkup.ispisi();

    Skup<string> stringSkup;
    stringSkup.dodaj("Apple");
    stringSkup.dodaj("Banana");
    stringSkup.dodaj("Apple"); 
    stringSkup.ispisi();

    return 0;
}
