//
// Life and Death of a Bunny-Family
//
//
//


#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function to determine sex
char randsex(void);

// Function to determine colour
string randColour(void);

// Function to determine name
string randName(void);

// Funktion to determine crazyness
int randCrazyness(void);

// Create bunny


int main()
{
	struct bunny
	{
		char sex{};
		char colour{};
		int age{};
		string name{};
		int crazy{};
	};

	// creating a bunny
	int bunnyNumber{};


}

// Function to determine sex
char randSex()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 2);
	int diceRoll = distribution(generator);

	if (diceRoll == 1)
		return 'm';
	else
		return 'f';
}

// Function to determine colour
string randColour()
{
	string colours[] = { "white", "brown", "red", "black", "yellow", "spotted" };

	random_device generator;
	uniform_int_distribution<int> distribution(0, 5);
	int diceRoll = distribution(generator);

	return colours[diceRoll];
}

// Function to determine name
string randName(void)
{
	string bunnyNames[] = { "Thumper", "Oreo", "Daisy", "Bella", "Charlie", "Lily", "Lola", "Oliver", "Jack", "Lucy", "Molly", "Peanut", "Coco", "Bailey", "Clover", "Pepper", "Bunbun", "Smokey", "Fluffy", "Gizmo", "Honey", "Willow", "Ginger", "Chloe", "Luna", "Snowball", "Cocoa", "Lucky", "Holly", "Jasper", "Buddy", "Cookie", "Hazel", "Peter", "Ruby", "Pumpkin", "Buster", "Max", "Nibbles", "Sophie", "Binky", "George", "Lilly", "Shadow", "Harvey", "Midnight", "Alice", "Flopsy", "Lulu" };

	random_device generator;
	uniform_int_distribution<int> distribution(0, 48);
	int diceRoll = distribution(generator);

	return bunnyNames[diceRoll];
}

// Funktion to determine crazyness
int randCrazyness(void)
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 100);
	int diceRoll = distribution(generator);

	if (diceRoll == 1 || diceRoll == 2)
		return 1;
	else 
		return 0;
}