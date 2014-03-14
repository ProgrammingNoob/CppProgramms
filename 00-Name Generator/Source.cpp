#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <time.h>

/*Global Array*/
std::string FirstName[100] = { "Michael","Christopher","Joshua","Matthew","Daniel","David","Andrew","Justin","Ryan","Robert","James","Nicholas","Joseph","Keeth","John","Jonathan","Kevin","Kyle","Brandon","William",
"Eric","Jose","Steven","Jacob","Brian","Tyler","Zachary","Aaron","Alexander","Adam","Thomas","Richard","Timothy","Benjamin","Jason","Jeffrey","Sean","Jordan","Jeremy","Travis","Cody","Nathan","Mark","Jesse","Charles",
"Juan", "Samuel","Patrick","Dustin","Scott","Stephen","Paul","Bryan","Luis","Derek","Austin","Kenneth","Carlos","Gregory","Alex","Cameron","Jared","Jesus","Bradley","Christian","Corey","Victor","Cory","Miguel","Tylor",
"Edward", "Francisco", "Trevor", "Adrian", "Jorge", "Ian", "Antonio", "Shawn", "Ricardo", "Vincent", "Edgar", "Erik", "Peter", "Shane", "Evan", "Chad", "Alejandro", "Brett","Gabriel","Eduardo","Raymond","Phillip",
"Mario", "Marcus", "Manuel", "George","Martin","Spencer","Garrett","Casey" };

std::string LastName[100] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez",
"Robinson","Clark","Rodriguez","Lewis","Lee","Walker","Hall","Allen","Young","Hernandez","King","Wright","Lopez","Hill","Scott","Green","Adams","Baker","Gonzalez","Nelson","Carter","Mitchell","Perez","Roberts","Turner",
"Phillips", "Campbell", "Parker","Evans","Edwards","Collins","Stewart","Sanchez","Morris","Rogers","Reed","Cook","Morgan","Bell","Murphy","Bailey","Rivera","Cooper","Richardson","Cox","Howard","Ward","Torres","Peterson",
"Gray", "Ramirez", "James", "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", "Henderson", "Coleman", "Jenkins", "Perry", "Powell", "Long", "Patterson", "Hughes", "Flores", "Washington",
"Butler", "Simmons", "Foster", "Gonzales", "Bryant", "Alexander","Russell","Griffin","Diaz","Hayes"};

int NumberOfNamesToCompareAgainst = 0;
int NumberOfNamesToGenerate = 0;
int RandomFirstNameNumber = 0;
int RandomLastNameNumber = 0;
char WriteToFileChoice;
/*EOF*/

void PrintList();
void PrintToFile();

int main()
{
	srand((unsigned int)time(NULL));

	std::cout << "Random Name Generator. 4Chan /G/.\n\n";
	std::cout << "Please enter the amount of names you wish to generate (1 - 100): ";
	std::cin >> NumberOfNamesToGenerate;
	
	if (std::cin.fail() || NumberOfNamesToGenerate > 100)
	{
		std::cout << "Not a valid number, defaulting to 10.\n";
		std::cout << "Not writing to file.\n\n";
		NumberOfNamesToGenerate = 10;
		PrintList();
		_getch();
		return EXIT_SUCCESS; //Early Exit.
	}

	std::cout << "\nWould you like to export the list to a file? (Y/N): ";
	std::cin.clear();

	std::cin >> WriteToFileChoice;
	WriteToFileChoice = toupper(WriteToFileChoice);

	switch (WriteToFileChoice)
	{
	case 'Y':
		PrintToFile();
		break;
	case 'N':
		PrintList();
		break;

	case 'G':
		std::cout << "Hello /G/! You Found The First Easter Egg! Post In The Thread If You See This";
		std::cin.get();
		std::cin.ignore();
		return 0;
		break;

	default:
		std::cout << "Not a valid choice, defaulting to no.\n\n";
		PrintList();
		_getch();
		break;
	}
	std::cin.get();
	std::cin.ignore();
}

void PrintList()
{
	while (NumberOfNamesToGenerate > NumberOfNamesToCompareAgainst)
	{
		RandomFirstNameNumber = rand() % 100 + 1;
		RandomLastNameNumber = rand() % 100;
		std::cout << FirstName[RandomFirstNameNumber] << " " << LastName[RandomLastNameNumber] << std::endl;
		NumberOfNamesToCompareAgainst++;
	};

}

void PrintToFile()
{
	std::fstream NameList("Name List.txt",std::ios::out);
	while (NumberOfNamesToGenerate > NumberOfNamesToCompareAgainst)
	{
		RandomFirstNameNumber = rand() % 100 + 1;
		RandomLastNameNumber = rand() % 100 + 1;
		NameList << FirstName[RandomFirstNameNumber] << " " << LastName[RandomLastNameNumber] << std::endl;
		NumberOfNamesToCompareAgainst++;
	};
	std::cout << "\n\nDone.";
}