#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Enemy {
protected:
    string name;
    int health;
    int damage;

public:
    Enemy(const string& name, int health, int damage) 
    {
        if (health < 0 || damage < 0) throw invalid_argument("Health i damage moraju biti nenegativni.");
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    virtual void attack() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Enemy() {}
};

class Boss : public Enemy 
{
    string weapon;

public:
    Boss(const string& name, int health, int damage, const string& weapon) : Enemy(name, health, damage) 
    {
        if (weapon.empty()) throw invalid_argument("Weapon ne smije biti prazan.");
        this->weapon = weapon;
    }

    void attack() const override 
    {
        cout << name << " napada s oruzjem \"" << weapon << "\" nanoseci " << damage << " stete!" << endl;
    }

    void displayInfo() const override 
    {
        cout << "Boss: " << name << ", HP: " << health << ", Steta: " << damage << ", Oruzje: " << weapon << endl;
    }
};

class Monster : public Enemy 
{
    string ability;

public:
    Monster(const string& name, int health, int damage, const string& ability) : Enemy(name, health, damage) 
    {
        if (ability.empty()) throw invalid_argument("Ability ne smije biti prazan.");
        this->ability = ability;
    }

    void attack() const override 
    {
        cout << name << " koristi sposobnost \"" << ability << "\" i nanosi " << damage << " stete!" << endl;
    }

    void displayInfo() const override 
    {
        cout << "Monster: " << name << ", HP: " << health << ", Steta: " << damage << ", Sposobnost: " << ability << endl;
    }
};

int main() 
{
    try {
            vector<shared_ptr<Enemy>> enemies = {
            make_shared<Boss>("Gospodar", 150, 25, "Mac tame"),
            make_shared<Monster>("Zvijer", 120, 20, "Vatreni dah")
        };

        for (const auto& enemy : enemies) 
        {
            enemy->displayInfo();
            enemy->attack();
            cout << endl;
        }

        try 
        {
            Boss("Neispravan Boss", 100, 20, "");
        }
        catch (const invalid_argument& e) 
        {
            cout << "Greska: " << e.what() << endl;
        }

        try 
        {
            Monster("Neispravan Monster", 90, 15, "");
        }
        catch (const invalid_argument& e) 
        {
            cout << "Greska: " << e.what() << endl;
        }

    }
    catch (const exception& e) 
    {
        cout << "Greska: " << e.what() << endl;
    }

    return 0;
}
