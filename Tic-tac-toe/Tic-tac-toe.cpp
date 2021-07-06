#include <iostream>
#include "Tic-tac-toe.h"
const int sizeMap = 3;

void FillMapDeffoltValue(int**& map)
{
	int count = 1;
	for(size_t i = 0; i < sizeMap; i++)
	{
		for(size_t j = 0; j < sizeMap; j++)
		{
			map[i][j] = count++;
		}
	}
}

void ShowMap(int**& map, int value = -1)
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
				case -1:
					std::cout << 'X';
					break;
				default:
					std::cout << ' ';
					break;
			}
		}
		std::cout << "\n";
	}
}

bool IsEmptyOn(int**& map, int i, int j)
{
	return map[i][j] != 0 && map[i][j] != -1;
}

bool IsEmptyCell(int value, int**& map)
{
	bool isEmpty = false;
	switch(value)
	{
		case 1:
			isEmpty = IsEmptyOn(map, 0, 0); break;
		case 2:
			isEmpty = IsEmptyOn(map, 0, 1); break;
		case 3:
			isEmpty = IsEmptyOn(map, 0, 2); break;
		case 4:
			isEmpty = IsEmptyOn(map, 1, 0); break;
		case 5:
			isEmpty = IsEmptyOn(map, 1, 1); break;
		case 6:
			isEmpty = IsEmptyOn(map, 1, 2); break;
		case 7:
			isEmpty = IsEmptyOn(map, 2, 0); break;
		case 8:
			isEmpty = IsEmptyOn(map, 2, 1); break;
		case 9:
			isEmpty = IsEmptyOn(map, 2, 2); break;
		default:
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
			break;
	}
	return isEmpty;
}

int GetUserInput()
{
	int value;
	bool isEmptyCell = false;
	while(isEmptyCell == false)
	{
		std::cout << "Введите координату 1-9: ";
		try
		{
			std::cin >> value;
		}
		catch(...)
		{
			std::cout << "Вводить можно только цифры!!!\n";
			continue;
		}

		if(value >= 1 && value <= 9)
		{
			return value;
		}
		else
		{
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
		}

	}
	return value;
}

void SetValueOnMap(int position, int value, int**& map)
{
	switch(position)
	{
		case 1:
			map[0][0] = value; break;
		case 2:
			map[0][1] = value; break;
		case 3:
			map[0][2] = value; break;
		case 4:
			map[1][0] = value; break;
		case 5:
			map[1][1] = value; break;
		case 6:
			map[1][2] = value; break;
		case 7:
			map[2][0] = value; break;
		case 8:
			map[2][1] = value; break;
		case 9:
			map[2][2] = value; break;
		default:
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
			break;
	}
}

bool CheckWin(int**& map)
{
	for(size_t i = 0; i < sizeMap; i++)
	{
		if(map[0][i] == map[1][i] && map[0][i] == map[2][i] && map[1][i] == map[2][i])
		{
			return true;
		}

		if(map[i][0] == map[i][1] && map[i][0] == map[i][2] && map[i][1] == map[i][2])
		{
			return true;
		}
	}
	if(map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[1][1] == map[2][2])
	{
		return true;
	}

	return map[0][2] == map[1][1] && map[0][2] == map[2][0] && map[1][1] == map[2][0];
}

int GetUserPosition(int**& map)
{
	bool isCorrect = false;
	int position;
	while(isCorrect == false)
	{
		position = GetUserInput();
		isCorrect = IsEmptyCell(position, map);
	}
	return position;
}

int GetPositionForWin(int**& map, int value)
{
	int countEqual = 0;
	int indexJ;
	for(size_t i = 0; i < sizeMap; i++)
	{
		for(size_t j = 0; j < sizeMap; j++)
		{
			if(map[i][j] != value)
			{
				indexJ = j;
			}
			else
			{
				countEqual++;
			}
		}
		if(countEqual == 2 && map[i][indexJ]!= 0 && map[i][indexJ] != -1)
		{
			return map[i][indexJ];
		}
		countEqual = 0;
	}

	for(size_t i = 0; i < sizeMap; i++)
	{
		for(size_t j = 0; j < sizeMap; j++)
		{
			if(map[j][i] != value)
			{
				indexJ = j;
			}
			else
			{
				countEqual++;
			}
		}
		if(countEqual == 2 && map[i][indexJ] != 0 && map[i][indexJ] != -1)
		{
			return map[indexJ][i];
		}
		countEqual = 0;
	}

	if(map[2][0] == map[1][1] && map[0][2] == 3)
	{
		return 3;
	}
	else if(map[2][0] == map[0][2] && map[1][1] == 5)
	{
		return 5;
	}
	else if(map[1][1] == map[0][2] && map[2][0] == 7)
	{
		return 7;
	}
	else if(map[0][0] == map[1][1] && map[2][2] == 9)
	{
		return 9;
	}
	else if(map[1][1] == map[2][2] && map[0][0] == 1)
	{
		return 1;
	}
	else if(map[0][0] == map[2][2] && map[1][1] == 5)
	{

	}

	return -2;
}

void AITurn(int**& map, int  positionCorners[4])
{
	int position;
	bool isCorrect = false;
	while(isCorrect == false)
	{
		position = GetPositionForWin(map, -1);
		if(position != -2)
		{
			isCorrect = IsEmptyCell(position, map);
			SetValueOnMap(position, -1, map);
		}
		else
		{
			position = rand() % 3;
			isCorrect = IsEmptyCell(positionCorners[position], map);
			SetValueOnMap(positionCorners[position], -1, map);
		}
	}
}

int FindBestCorner(int**& map)
{
	if(map[0][0] == 1 && map[0][1] == 2 && map[1][0] == 4)
	{
		return 1;
	}
	else if(map[0][2] == 3 && map[0][1] == 2 && map[1][2] == 6)
	{
		return 3;
	}
	else if(map[2][0] == 7 && map[1][0] == 4 && map[2][1] == 8)
	{
		return 7;
	}
	else if (map[2][2] == 9 && map[1][2] == 6 && map[2][1] == 8)
	{
		return 9;
	}
	else
	{
		std::cout << "Error in FindBestCorner";
	}
}

void StartGameAIFirst()
{
	srand(time(0));
	int positionCorners[] = {1,3,7,9};
	int** map = new int* [sizeMap];
	for(size_t i = 0; i < sizeMap; i++)
	{
		map[i] = new int[sizeMap];
	}
	FillMapDeffoltValue(map);

	map[1][1] = -1; // робот ставит крестик в центр
	ShowMap(map);
	int position;
	position = GetUserPosition(map);
	SetValueOnMap(position, 0, map);

	bool isCorrect = false;
	ShowMap(map);
	if(position == 2 || position == 4 || position == 6 || position == 8)
	{
		AITurn(map, positionCorners); // робот ставит в любой угол крестик
		ShowMap(map);

		position = GetUserPosition(map);
		SetValueOnMap(position, 0, map);
		ShowMap(map);

		position = GetPositionForWin(map, -1);
		if(position != -2)
		{
			SetValueOnMap(position, -1, map);
		}
		else
		{
			position = FindBestCorner(map);
			SetValueOnMap(position, -1, map); // 
		}		
		ShowMap(map);
		if(CheckWin(map))
		{
			return;
		}

		position = GetUserPosition(map);
		SetValueOnMap(position, 0, map);
		ShowMap(map);

		SetValueOnMap(GetPositionForWin(map, -1) , -1, map);
		ShowMap(map);

		if(CheckWin(map))
		{
			return;
		}
		position = GetUserPosition(map);
		SetValueOnMap(position, 0, map);
		ShowMap(map);
		while(isCorrect == false)
		{
			position = GetPositionForWin(map, -1);
			if(position != -2)
			{
				isCorrect = IsEmptyCell(position, map);
				if(isCorrect)
				{
					SetValueOnMap(position, -1, map);
				}
			}
			else
			{
				position = rand() % 3;
				isCorrect = IsEmptyCell(positionCorners[position], map);
				if(isCorrect)
				{
					SetValueOnMap(positionCorners[position], -1, map);
				}
			}
		}
		ShowMap(map);
		if(CheckWin(map))
		{
			return;
		}
	}
	else
	{

	}

	for(size_t i = 0; i < sizeMap; i++)
	{
		delete[] map[i];
	}
	delete[] map;
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
				std::system("cls");
				std::cout << "Первым ходит пользователь.\n";
				
				break;

			case 2:
				std::system("cls");
				std::cout << "Первым ходит компьютер.\n";
				StartGameAIFirst();
				break;
			case 3:
				isExit = true;
				std::system("cls");
				std::cout << "Программа закончила свою работу.\n";
				break;
			default:
				std::cout << "Нет такой команды!\n";
				break;
		}
	}
}

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	ShowMenu();
}