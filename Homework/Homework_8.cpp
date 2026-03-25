#include <iostream>
#include <string>
using namespace std;

//class for the player
class Player
{
    public:

    //basic attack (no parameters)
    void attack()
    {
        cout << "Player attacks rock with a basic attack!" << endl;
    }

    //attack with damage
    void attack(int damage)
    {
        cout << "Player attacks rock and deals " << damage << " damage!" << endl;
    }

    //magic attack with spell name and damage
    void attack(string spellName, int damage)
    {
        cout << "Player casts a spell " << spellName << " and deals " << damage << " damage!" << endl;
    }
};

int main()
{
    //making an object
    Player p;

    //calling the different attacks
    //first attack (no input)
    p.attack();

    //second attack (with damage)
    p.attack(10);

    //third attack (with spell name and damage)
    p.attack("Fireball", 20);

    return 0;
}