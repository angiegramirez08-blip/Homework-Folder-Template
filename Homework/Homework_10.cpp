#include <iostream>
using namespace std;

//base class
class Pokemon {
protected:
    int level;

public:
    Pokemon(int lvl) {
        level = lvl;
    }

    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() const = 0;
};

//intermediate class
class PokemonType : public Pokemon {
public:
    PokemonType(int lvl) : Pokemon(lvl) {}
    virtual string getType() const = 0;
};

//electric type class
class ElectricPokemon : public PokemonType{
public:
    ElectricPokemon(int lvl) : PokemonType(lvl) {}
    string getType() const {
        return "Electric";
    }
};

//Pikachu class
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int lvl) : ElectricPokemon(lvl) {}
    void attack() const {
        cout << "Pikachu uses Thunderbolt!" << endl;
    }

    void defend() const {
        cout << "Pikachu uses Quick Attack to dodge!" << endl;
    }

    void evolve() const {
        cout << "Pikachu evolves into Raichu!" << endl;
    }
};

int main() {
    Pikachu p(10);

    cout << "Pokemon type: " << p.getType() << endl;

    p.attack();
    p.defend();
    p.evolve();

    return 0;
}

