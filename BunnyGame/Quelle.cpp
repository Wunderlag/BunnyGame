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
	struct bunny* next;
};

bunny *listStart{};

// Function to determine sex
char randSex(void);
// Funtion to determine age of starting bunnies
int randAge(void);
// Function to determine colour
string randColour(void);
// Function to determine name
string randName(char);
// Funktion to determine crazyness
int randCrazyness(void);
// Create bunny
void createBunny(int, char);
// Add a Node to Bunny
void addNode(bunny*);
// output for the Bunny list
void listOutput(void);
// breeding mechanism
int bunnyCounting(void);
// lets bunnies age one year each cycle, kills them when older than 10yrs
void bunnyAging(void);

int main()
{
	// creating first bunnies
	createBunny(5, 'y'); // first parameter determines how many bunnies will be created, 2nd parameter only on gamestart 'y', else 'n'

	// bunny breeding
	int gameOver{ 1 };
	while (gameOver >= 1)
	{
		bunnyAging();
		createBunny(bunnyCounting(), 'n');
		listOutput();
		system("PAUSE");

	}






	// Test output
	//listOutput();

	// cout << "\nErgebnis:\n" << bunnyCounting() << endl;

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

// Funtion to determine age of starting bunnies
int randAge()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 10);
	int diceRoll = distribution(generator);

	return diceRoll;
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
string randName(char sex)
{
	string bunnyFemNames[24] = { "Daisy", "Bella", "Lily", "Lola", "Lucy", "Molly", "Bailey", "Bunbun", "Fluffy", "Honey", "Willow", "Ginger", "Chloe", "Luna", "Snowball", "Cocoa", "Holly", "Cookie", "Ruby", "Pumpkin", "Sophie", "Lilly", "Alice", "Lulu" };
	string bunnyMaleNames[24] = { "Thumper", "Oreo", "Charlie", "Oliver", "Jack", "Clover", "Smokey", "Gizmo", "Binky", "George", "Max", "Nibbles", "Harvey", "Buster", "Peter", "Jasper", "Buddy", "Lucky", "Shadow", "Flopsy", "Pepper", "Hazel", "Midnight", "Peanut" };
	random_device generator;
	uniform_int_distribution<int> distribution(0, 23);
	int diceRoll = distribution(generator);

	if (sex == 'f')
	{
		return bunnyFemNames[diceRoll];
	}
	else if (sex == 'm')
	{
		return bunnyMaleNames[diceRoll];
	}
}

// Funktion to determine crazyness
int randCrazyness()
{
	random_device generator;
	uniform_int_distribution<int> distribution(1, 100);
	int diceRoll = distribution(generator);

	if (diceRoll <= 2)
		return 1;
	else 
		return 0;
}

// Create Bunny
void createBunny(int max, char start)
{
	int n{};

	for (n = 0; n < max; n++)
	{
		bunny* add = new bunny;
		add->sex = randSex();
		add->colour = randColour();
		if (start == 'y')
		{
			add->age = randAge();
		}
		else if (start == 'n')
		{
			add->age = 0;
		}
		add->name = randName(add->sex); 	// Name depending on sex
		add->crazy = randCrazyness();
		addNode(add);
	}
	
}

// Add a Node to Bunny
void addNode(bunny* add)
{
	if (listStart == 0)
	{
		listStart = add;
		add->next = 0;
	}
	else
	{
		bunny* nPtr = listStart;
		while (nPtr->next != 0)
		{
			nPtr = nPtr->next;
		}
		nPtr->next = add;
		add->next = 0;
	}
	//cout << add->name << "\n" << add->sex << "\n" << add->colour << "\n" << add->age << "\n" << add->crazy << "\n" << endl;

}

// output for the Bunny list
void listOutput()
{
	bunny* nPtr = listStart;
	while (nPtr != 0)
	{
		cout << nPtr->name << "\n" << nPtr->sex << "\n" << nPtr->colour << "\n" << nPtr->age << "\n" << nPtr->crazy << "\n" << endl;
		nPtr = nPtr->next;
	}
	
}

// breeding mechanism
// "as long as there is a male bunny age 2 or up, every female bunny age 2 or up will create one new bunny age 1. Crazy bunnies will not breed!"
int bunnyCounting(void)
{
	// is there a male age 2 or up?
	char sexTest{};
	int ageTest{};
	int crazyTest{};
	bunny* nPtr = listStart;
	while ((sexTest != 'm' && nPtr != 0) || (ageTest < 2 && nPtr != 0) || (crazyTest == 1 && nPtr != 0))
	{
		sexTest = nPtr->sex;
		ageTest = nPtr->age;
		crazyTest = nPtr->crazy;
		nPtr = nPtr->next;
	}
	if (sexTest != 'm' || ageTest < 2 || crazyTest == 1)
	{
		return 0;
	}
	
	// since there is a not-crazy male bunny age 2 or up available, lets check for at least 1 female bunny
	sexTest = 0;
	ageTest = 0;
	crazyTest = 0;
	nPtr = listStart;
	while ((sexTest != 'f' && nPtr != 0) || (ageTest < 2 && nPtr != 0) || (crazyTest == 1 && nPtr != 0))
	{
		sexTest = nPtr->sex;
		ageTest = nPtr->age;
		crazyTest = nPtr->crazy;
		nPtr = nPtr->next;
	}
	if (sexTest != 'f' || ageTest < 2 || crazyTest == 1)
	{
		return 0;
	}

	// counting female bunnies
	sexTest = 0;
	ageTest = 0;
	crazyTest = 0;
	int femaleCounter{};
	nPtr = listStart;
	while (nPtr != 0)
	{
		sexTest = nPtr->sex;
		ageTest = nPtr->age;
		crazyTest = nPtr->crazy;
		nPtr = nPtr->next;
		if (sexTest == 'f' && ageTest >= 2 && crazyTest == 0)
		{
			femaleCounter++;
		}
	}

	return femaleCounter;
}

// lets bunnies age one year each cycle, kills them when older than 10yrs
void bunnyAging(void)
{
	bunny* nPtr = listStart;
	bunny* resetPtr = listStart;
	while (nPtr != 0)
	{
		nPtr->age++;
		
		if (nPtr->age > 10)
		{
			if (nPtr == listStart)
			{
				resetPtr = listStart;
				listStart = nPtr->next;
				nPtr = nPtr->next;
				delete resetPtr;
				resetPtr = listStart;
			}
			else
			{
				nPtr = nPtr->next;
				delete resetPtr->next;
				resetPtr->next = nPtr;
			}
		}
		else
		{
			resetPtr = nPtr;
			nPtr = nPtr->next;
		}
	}
}