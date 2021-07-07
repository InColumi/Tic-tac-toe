#include <iostream>
const int SizeMap = 3;

int** Map;

void FillMapDeffoltValue()
{
	int count = 1;
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			Map[i][j] = count++;
		}
	}
}

void ShowMap()
{
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			switch(Map[i][j])
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

bool IsEmptyOn(int i, int j)
{
	return Map[i][j] != 0 && Map[i][j] != -1;
}

bool IsEmptyCell(int value)
{
	bool isEmpty = false;
	switch(value)
	{
		case 1:
			isEmpty = IsEmptyOn(0, 0); break;
		case 2:
			isEmpty = IsEmptyOn(0, 1); break;
		case 3:
			isEmpty = IsEmptyOn(0, 2); break;
		case 4:
			isEmpty = IsEmptyOn(1, 0); break;
		case 5:
			isEmpty = IsEmptyOn(1, 1); break;
		case 6:
			isEmpty = IsEmptyOn(1, 2); break;
		case 7:
			isEmpty = IsEmptyOn(2, 0); break;
		case 8:
			isEmpty = IsEmptyOn(2, 1); break;
		case 9:
			isEmpty = IsEmptyOn(2, 2); break;
		default:
			std::cout << "Выбранная Вами ячейка уже занята\n";
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
		std::cin >> value;


		if(value >= 1 && value <= 9)
		{
			isEmptyCell = true;
		}
		else
		{
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
			value = 0;
		}

	}

	return value;
}

void SetValueOnMap(int position, int value)
{
	switch(position)
	{
		case 1:
			Map[0][0] = value; break;
		case 2:
			Map[0][1] = value; break;
		case 3:
			Map[0][2] = value; break;
		case 4:
			Map[1][0] = value; break;
		case 5:
			Map[1][1] = value; break;
		case 6:
			Map[1][2] = value; break;
		case 7:
			Map[2][0] = value; break;
		case 8:
			Map[2][1] = value; break;
		case 9:
			Map[2][2] = value; break;
		default:
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
			break;
	}
}

bool CheckWin()
{
	for(size_t i = 0; i < SizeMap; i++)
	{
		if(Map[0][i] == Map[1][i] && Map[0][i] == Map[2][i] && Map[1][i] == Map[2][i])
		{
			return true;
		}

		if(Map[i][0] == Map[i][1] && Map[i][0] == Map[i][2] && Map[i][1] == Map[i][2])
		{
			return true;
		}
	}
	if(Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2] && Map[1][1] == Map[2][2])
	{
		return true;
	}

	if(Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0] && Map[1][1] == Map[2][0])
	{
		return true;
	}

	int countPosition = 0;
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			countPosition++;
			if(Map[i][j] == countPosition)
			{
				return false;
			}
		}
	}

	return true;
}

int GetUserPosition()
{
	bool isCorrect = false;
	int position;
	while(isCorrect == false)
	{
		position = GetUserInput();
		isCorrect = IsEmptyCell(position);
	}
	return position;
}

int GetPositionForWin(int value)
{
	int countEqual = 0;
	int indexJ;
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			if(Map[i][j] != value)
			{
				indexJ = j;
			}
			else
			{
				countEqual++;
			}
		}
		if(countEqual == 2 && Map[i][indexJ] != 0 && Map[i][indexJ] != -1)
		{
			return Map[i][indexJ];
		}
		countEqual = 0;
	}

	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			if(Map[j][i] != value)
			{
				indexJ = j;
			}
			else
			{
				countEqual++;
			}
		}
		if(countEqual == 2 && Map[indexJ][i] != 0 && Map[indexJ][i] != -1)
		{
			return Map[indexJ][i];
		}
		countEqual = 0;
	}

	if(Map[2][0] == Map[1][1] && Map[0][2] == 3)
	{
		return 3;
	}
	else if(Map[2][0] == Map[0][2] && Map[1][1] == 5)
	{
		return 5;
	}
	else if(Map[1][1] == Map[0][2] && Map[2][0] == 7)
	{
		return 7;
	}
	else if(Map[0][0] == Map[1][1] && Map[2][2] == 9)
	{
		return 9;
	}
	else if(Map[1][1] == Map[2][2] && Map[0][0] == 1)
	{
		return 1;
	}
	else if(Map[0][0] == Map[2][2] && Map[1][1] == 5)
	{
		return 5;
	}

	return -2;
}

int FindBestCorner()
{
	if(Map[0][0] == 1 && Map[0][1] == 2 && Map[1][0] == 4)
	{
		return 1;
	}
	else if(Map[0][2] == 3 && Map[0][1] == 2 && Map[1][2] == 6)
	{
		return 3;
	}
	else if(Map[2][0] == 7 && Map[1][0] == 4 && Map[2][1] == 8)
	{
		return 7;
	}
	else if(Map[2][2] == 9 && Map[1][2] == 6 && Map[2][1] == 8)
	{
		return 9;
	}
	else
	{
		return -2;
	}
}

int FindEmptyCell()
{
	int countPosition = 0;
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			countPosition++;
			if(Map[i][j] != 0 && Map[i][j] != -1)
			{
				return countPosition;
			}
		}
	}

	return -2;
}

void AITurn(int positionCorners[4], int symbolUser, int symbolAI)
{
	int position;

	position = GetPositionForWin(symbolAI);
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	position = GetPositionForWin(symbolUser);
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	position = FindBestCorner();
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	position = FindEmptyCell();
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	bool isCorrect = false;
	while(isCorrect == false)
	{
		position = rand() % 3;
		isCorrect = IsEmptyCell(positionCorners[position]);
		SetValueOnMap(positionCorners[position], symbolAI);
	}
}

void MamoryAlocationForMap()
{
	Map = new int* [SizeMap];
	for(size_t i = 0; i < SizeMap; i++)
	{
		Map[i] = new int[SizeMap];
	}
}

void DeleteMap()
{
	for(size_t i = 0; i < SizeMap; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;
}

void StartGameAIFirst(int positionCorners[4])
{
	int symbolUser = 0;
	int symbolAI = -1;

	MamoryAlocationForMap();
	FillMapDeffoltValue();

	Map[1][1] = -1; // робот ставит крестик в центр
	ShowMap();

	int position;
	position = GetUserPosition(); // Ввод пользователя
	SetValueOnMap(position, symbolUser);

	bool isCorrect = false;
	ShowMap();
	if(position == 2 || position == 4 || position == 6 || position == 8)
	{
		// робот ставит в любой угол крестик
		bool isCorrect = false;
		while(isCorrect == false)
		{
			position = rand() % 3;
			isCorrect = IsEmptyCell(positionCorners[position]);
			SetValueOnMap(positionCorners[position], symbolAI);
		}
		ShowMap();

		// Ввод пользователя
		position = GetUserPosition();
		SetValueOnMap(position, symbolUser);
		ShowMap();

		// Робот ставит либо последний ход, либо предпоследний ход перед победой
		position = GetPositionForWin(symbolAI);
		if(position != -2)
		{
			SetValueOnMap(position, symbolAI);
		}
		else
		{
			position = FindBestCorner();
			SetValueOnMap(position, symbolAI); // 
		}
		ShowMap();
		if(CheckWin())
		{
			return;
		}

		// Ввод пользователя
		position = GetUserPosition();
		SetValueOnMap(position, symbolUser);
		ShowMap();

		// Последний ход робота
		SetValueOnMap(GetPositionForWin(symbolAI), symbolAI);
		ShowMap();

		if(CheckWin())
		{
			return;
		}
	}
	else
	{
		bool isUser = false;
		while(CheckWin() == false)
		{
			if(isUser == false)
			{
				AITurn(positionCorners, symbolUser, symbolAI);
				isUser = true;
			}
			else
			{
				position = GetUserPosition(); // Ввод пользователя
				SetValueOnMap(position, symbolUser);
				isUser = false;
			}
			ShowMap();
		}
	}

	DeleteMap();
}

void StartGameUserFirst(int positionCorners[4])
{
	int symbolUser = -1;
	int symbolAI = 0;

	MamoryAlocationForMap();
	FillMapDeffoltValue();
	// Ввод пользователя
	int position;
	position = GetUserPosition();
	SetValueOnMap(position, symbolUser);
	ShowMap();

	bool isUser = false;
	if(Map[1][1] != 5)
	{
		while(CheckWin() == false)
		{
			if(isUser == false)
			{
				AITurn(positionCorners, symbolUser, symbolAI);
				isUser = true;
			}
			else
			{
				// Ввод пользователя
				position = GetUserPosition();
				SetValueOnMap(position, symbolUser);
				isUser = false;
			}
			ShowMap();
		}
	}
	else
	{
		Map[1][1] = symbolAI;
		ShowMap();
		while(CheckWin() == false)
		{
			if(isUser == false)
			{
				// Ввод пользователя
				position = GetUserPosition();
				SetValueOnMap(position, symbolUser);
				isUser = true;
			}
			else
			{
				AITurn(positionCorners, symbolUser, symbolAI);
				isUser = false;
			}
			ShowMap();
		}
	}

	DeleteMap();
}

void ShowMenu()
{
	srand(time(0));
	int positionCorners[] = {1,3,7,9};
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
				StartGameUserFirst(positionCorners);
				break;

			case 2:
				std::system("cls");
				std::cout << "Первым ходит компьютер.\n";
				StartGameAIFirst(positionCorners);
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