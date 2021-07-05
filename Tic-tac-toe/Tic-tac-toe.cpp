#include <iostream>
const int sizeMap = 3;

void FillMapDeffoltValue(int** map, int value = -1)
{
	for(size_t i = 0; i < sizeMap; i++)
	{
		for(size_t j = 0; j < sizeMap; j++)
		{
			map[i][j] = value;
		}
	}
}

void ShowMap(int** map, int value = -1)
{
	for(size_t i = 0; i < sizeMap; i++)
	{
		for(size_t j = 0; j < sizeMap; j++)
		{
			switch(map[i][j])
			{
				case 0:
					std::cout << 'O';
					break;
				case 1:
					std::cout << 'X';
					break;
				case -1:
					std::cout << ' ';
					break;
				default:
					std::cout << "Error in map!";
					break;
			}
		}
		std::cout << "\n";
	}
}

void ShowMenu()
{	
	bool isExit = false;
	int numberOfCommand;
	while(isExit == false)
	{
		std::cout << "Выберете кто будет ходить первым:\n";
		std::cout << "\t1 - пользователь.\n";
		std::cout << "\t2 - компьютер.\n";
		std::cout << "\t3 - выход из программы.\n";
		std::cin >> numberOfCommand;

		switch(numberOfCommand)
		{
			case 1:
				system("cls");
				std::cout << "Первым ходит пользователь.\n";
				break;

			case 2:
				system("cls");
				std::cout << "Первым ходит компьютер.\n";

				break;
			case 3:
				isExit = true;
				system("cls");
				std::cout << "Программа закончила свою работу.\n";
				break;
			default:
				std::cout << "Нет такой команды!\n";
				break;
		}
	}
}

void StartGame()
{
	int** map = new int* [sizeMap];
	for(size_t i = 0; i < sizeMap; i++)
	{
		map[i] = new int[sizeMap];
	}
	FillMapDeffoltValue(map, 1);




	for(size_t i = 0; i < sizeMap; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	
	ShowMenu();
}