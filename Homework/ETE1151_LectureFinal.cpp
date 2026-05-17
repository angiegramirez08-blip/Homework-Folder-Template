// ETE1151_LectureFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ANGIE RAMIREZ
// ETE 1151.02
// LECTURE FINAL
// 15 MAY 2026
// 
// In this code, I covered the topic of Smart Pointers through demostrating and performing three types of smart pointers
// in a simple program. I used unique_ptr, shared_ptr, and weak_ptr to show how they work and how they can be used to manage memory in C++.
// 
// The idea for this project is a Star Wars themed game similar to the pokemon game homework we had previously.
// In using smart pointers, we avoid memory leaks while the memory is managed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>

using namespace std;

//Weapon class
// This class represents a weapon that a character can use in the game.
// Application: Every spaceship has one weapon system. Weapon ONLY belongs to that ship

class Weapon {
private:
	string name;
	int damage;
public:
	Weapon(string weaponName, int weaponDamage)
	{
		name = weaponName;
		damage = weaponDamage;

		cout << "[Weapon Created] " << name << endl;
	}

	~Weapon()
	{
		cout << "[Weapon Destroyed] " << name << endl;
	}

	void fire()
	{
		cout << name
			<< " attacks for "
			<< damage
			<< " damage!" << endl;
	}
};

// Spaceship class
// This class represents a spaceship that can have a weapon and can be piloted by a character.
// Application: A spaceship owns its own weapon sysytem.

class Spaceship {
private:
	string shipName;
	unique_ptr<Weapon> weapon; // Unique pointer to a Weapon

public: //constructor recieved ownership of a weapon using move()
	Spaceship(string name, unique_ptr<Weapon> shipWeapon)
	{
		shipName = name;
		weapon = move(shipWeapon);
		cout << "[Spaceship Created] " << shipName << endl;
	}

	~Spaceship()
	{
		cout << "[Spaceship Destroyed] " << shipName << endl;
	}

	void attack()
	{
		cout << shipName << " is attacking!" << endl;
		weapon->fire();
	}
};

// Fleet class
// This class represents a fleet of spaceships. It uses shared pointers to manage the spaceships in the fleet.
// Application: Multiple Jedi can be a part of the same fleet

class Fleet {
private:
	string fleetName;

public:
	Fleet(string name)
	{
		fleetName = name;
		cout << "[Fleet Created] " << fleetName << endl;
	}

	~Fleet()
	{
		cout << "[Fleet Destroyed] " << fleetName << endl;
	}

	string getName()
	{
		return fleetName;
	}
};

// Foward declaration
// The Droid refrences Jedi before the Jedi class is defined, so we need to forward declare it.

class Jedi;
// Droid class
// Application: A Droid assists a Jedi, but does not own the Jedi. 
// weak_ptr is used to avoid circular reference between Jedi and Droid

class Droid {
private:
	string droidName;
	weak_ptr<Jedi> master; // Weak pointer to a Jedi

public:
	Droid(string name)
	{
		droidName = name;
		cout << "[Droid Activated] " << droidName << endl;
	}

	~Droid()
	{
		cout << "[Droid Destroyed] " << droidName << endl;
	}

	void assignMaster(shared_ptr<Jedi> jedi);
	void checkMaster();
};

// Jedi class
// Application: A Jedi can share ownership of fleets. Many Jedi can be part of the same fleet
// Multiple Jedi can share the same fleets, we use shared_ptr to manage the fleets.

class Jedi {
private:
	string jediName;
	shared_ptr<Fleet> fleet; // Shared pointer to a Fleet	

public:
	Jedi(string name)
	{
		jediName = name;
		cout << "[Jedi Created] " << jediName << endl;
	}

	~Jedi()
	{
		cout << "[Jedi Destroyed] " << jediName << endl;
	}

	string getName()
	{
		return jediName;
	}

	void joinFleet(shared_ptr<Fleet> newFleet)
	{
		fleet = newFleet;
		cout << jediName << " has joined the fleet: " << fleet->getName() << endl;
	}

	void showFleet()
	{
		if (fleet)
		{
			cout << jediName << " is part of the fleet: " << fleet->getName() << endl;
		}
		else
		{
			cout << jediName << " is not part of any fleet." << endl;
		}
	}
};

//Droid Functions
void Droid::assignMaster(shared_ptr<Jedi> jedi)
{
	master = jedi;
	cout << droidName << " is now assisting " << jedi->getName() << endl;
}

void Droid::checkMaster()
{
	// lock() is used to check if the master still exists. This TEMPORARILY converts weak_ptr to shared_ptr.
	// if object is not found/does not exsits, lock() returns nullptr

	shared_ptr<Jedi> temp = master.lock();
	if (temp)
	{
		cout << droidName << " is assisting " << temp->getName() << endl;
	}
	else
	{
		cout << droidName << " no longer has a master to assist." << endl;
	}
}

//Main function
int main()
{
	cout << "STAR WARS: Ultimate Edition" << endl;

	//PART 1: unique_ptr
	unique_ptr<Weapon> laser = make_unique<Weapon>("Laser Cannons", 120); //make_unique creates smart pointer safely

	//Transfering ownership into spaceship
	Spaceship falcon("Millennium Falcon", move(laser));

	//laser pointer becomes empty after move()
	if (!laser)
	{
		cout << "Weapon ownership has transferred to the spaceship successfully." << endl;
	}

	falcon.attack();
	cout << "\n======================================" << endl;

	//PART 2: shared_ptr
	shared_ptr<Fleet> rebelFleet = make_shared<Fleet>("Rebel Alliance Fleet"); //shared fleet object

	//Two Jedi sharing ownership of the same fleet
	shared_ptr<Jedi> obiwan = make_shared<Jedi>("Obi-Wan Kenobi");
	shared_ptr<Jedi> luke = make_shared<Jedi>("Luke Skywalker");

	luke->joinFleet(rebelFleet);
	obiwan->joinFleet(rebelFleet);

	cout << "\nFleet ownership count: " << rebelFleet.use_count() << endl; //should show 2
	cout << "\n======================================" << endl;

	//PART 3: weak_ptr
	Droid bb8("BB-8");
	bb8.assignMaster(luke); //BB-8 assists Luke
	bb8.checkMaster(); //BB-8 checks on Luke

	//Reset destroys Luke if not other shared_ptrs are owning him. Since BB-8 only has a weak reference, it does not prevent Luke from being destroyed.
	luke.reset(); //Luke is destroyed here
	cout << "\nLuke has left the ship." << endl;

	//weak_ptr safely checks if the master still exists without preventing destruction. Since Luke is destroyed, BB-8 should indicate that it no longer has a master.
	bb8.checkMaster(); //BB-8 checks on Luke again

	cout << "\n======================================" << endl;
	cout << "End of Star Wars: Ultimate Edition" << endl;

	return 0;
}

