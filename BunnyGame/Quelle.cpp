//
// Life and Death of a Bunny-Family
//
//
//


#include <iostream>
#include <string>
#include <random>

using namespace std;

// struct for bunny-data
struct bunny
{
	char sex{};
	string colour{};
	int age{};
	string name{};
	int crazy{};
} bunnyNumber[5]; // initialize without fixed array size??

// Function to determine sex
char randSex(void);

// Function to determine colour
string randColour(void);

// Function to determine name
string randName(void);

// Funktion to determine crazyness
int randCrazyness(void);

// Create bunny
void createBunny(int);

int main()
{
	// creating a bunny
	createBunny(5);






	// Test output
	int n{};

	for (n = 0; n  < 5; n++)
	{
		cout << bunnyNumber[n].name << "\n" << bunnyNumber[n].sex << "\n" << bunnyNumber[n].colour << "\n" << bunnyNumber[n].age << "\n" << bunnyNumber[n].crazy << "\n" << endl;
	}
	
		system("PAUSE");
	
	return 0;
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
int randCrazyness()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 100);
	int diceRoll = distribution(generator);

	if (diceRoll == 1 || diceRoll == 2)
		return 1;
	else 
		return 0;
}

// Create Bunny
void createBunny(int max)
{
	int n{};

	for (n = 0; n < max; n++)
	{
		bunnyNumber[n].sex = randSex();
		bunnyNumber[n].colour = randColour();
		bunnyNumber[n].age = 1;
		bunnyNumber[n].name = randName();
		bunnyNumber[n].crazy = randCrazyness();
	}

}