#include <iostream>
#include <conio.h>

void ConvertFromCel(float Temp);
void ConvertFromFer(float Temp);

int main()
{
	float Tempreture = 0.0;
	char TypeOfTemp = 'N';
	std::cout << "Please enter your tempreture: ";
	std::cin >> Tempreture;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\n\nStop trying to break me!\n";
		std::cout << "I'll close now! :(";
		_getch();
		return EXIT_FAILURE;
	}
	std::cout << "What do you want to convert to (C)elsius or (F)ahrenheit: ";
	std::cin >> TypeOfTemp;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "\n\nStop trying to break me!\n";
		std::cout << "I'll close now! :(";
		_getch();
		return EXIT_FAILURE;
	}
	TypeOfTemp = toupper(TypeOfTemp);
	switch (TypeOfTemp)
	{
	case 'C':
		ConvertFromFer(Tempreture); //The user wants Cel, from Fer
		break;
	case 'F':
		ConvertFromCel(Tempreture); //The user wants Fer, from Cel
		break;
	default:
		std::cout << "\n\nHow about no! This was the last straw :(";
		_getch();
		return EXIT_FAILURE;
	}
}

void ConvertFromCel(float Temp)
{
	float FTemp = Temp * 9 / 5 + 32;
	std::cout << FTemp;
	_getch();

}

void ConvertFromFer(float Temp)
{
	float CTemp = (Temp - 32) * 5 / 9;
	std::cout << CTemp;
	_getch();
}