#include <iostream>
/// <summary>
/// Размер поля
/// </summary>
const int SizeMap = 3;

/// <summary>
/// Карта матрица 3х3
/// </summary>
int** Map;

/// <summary>
/// Заполняет матрица цифрами 1-9(как клавиатура телефона)
/// </summary>
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

/// <summary>
/// Показывает карту на мониторе
/// </summary>
void ShowMap()
{
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			switch(Map[i][j])
			{
				case 0: // если значение на карте = 0, то выводит символ  О
					std::cout << 'O';
					break;
				case -1:// если значение на карте = -1, то выводит символ  Х
					std::cout << 'X';
					break;
				default:// в любом другом варианте выводит пробел
					std::cout << ' ';
					break;
			}
		}
		std::cout << "\n";
	}
}

/// <summary>
/// Проверяет пусатя ли ячейка по координатам i j
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
bool IsEmptyOn(int i, int j)
{
	return Map[i][j] != 0 && Map[i][j] != -1;
}

/// <summary>
/// Проверяет пустая ячейка на позиция 1-9
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
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

/// <summary>
/// Ввод пользователя
/// </summary>
/// <returns>возвращет значение пользователя</returns>
int GetUserInput()
{
	int value; // значение, которое введет пользователь
	bool isEmptyCell = false; // флаг проверки корректности
	while(isEmptyCell == false)
	{
		std::cout << "Введите координату 1-9: ";
		std::cin >> value;


		if(value >= 1 && value <= 9) // если введеное попадает в диапазон 1-9
		{
			isEmptyCell = true;
		}
		else // иначе выводит сообщение
		{
			std::cout << "Вводить можно только цифры 1-9. А Вы ввели " << value << '\n';
		}

	}

	return value;
}

/// <summary>
/// Ставит значение на указанную позицию
/// </summary>
/// <param name="position">позиция</param>
/// <param name="value">значение</param>
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

/// <summary>
/// Проверка победы
/// </summary>
/// <returns></returns>
bool CheckWin()
{
	// Проверка победы по вертикалям и Горизонталям
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

	// Проверка победы по диагонали
	if(Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2] && Map[1][1] == Map[2][2])
	{
		return true;
	}

	// Проверка победы по диагонали
	if(Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0] && Map[1][1] == Map[2][0])
	{
		return true;
	}

	// Проверка ничьи, если все ячейки заняты, то вернет true
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

/// <summary>
/// Считывает введенную позицию пользователя и проверят на пустоту.
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
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

/// <summary>
/// Возвращает ячейку для победы
/// </summary>
/// <param name="value">значение, что сравнивать O или X </param>
/// <returns></returns>
int GetPositionForWin(int value)
{
	// Считает кол-во совпадений. Должно быть 2 для возвращение позиции
	int countEqual = 0;

	// индекс стобца для верной позиции
	int indexJ;
	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			if(Map[i][j] != value) // если ячейка не равна значению
			{
				indexJ = j; // сохраняем позицию
			}
			else
			{
				countEqual++; // иначе считаем совпадения
			}
		}
		if(countEqual == 2 && Map[i][indexJ] != 0 && Map[i][indexJ] != -1) // если ячейка не занята, то возвращем 
		{
			return Map[i][indexJ];
		}
		countEqual = 0; // сбрасывем счетчик
	}

	for(size_t i = 0; i < SizeMap; i++)
	{
		for(size_t j = 0; j < SizeMap; j++)
		{
			if(Map[j][i] != value)// если ячейка не равна значению
			{
				indexJ = j;// сохраняем позицию
			}
			else
			{
				countEqual++;// иначе считаем совпадения
			}
		}
		if(countEqual == 2 && Map[indexJ][i] != 0 && Map[indexJ][i] != -1)// если ячейка не занята, то возвращем 
		{
			return Map[indexJ][i];
		}
		countEqual = 0; // сбрасывем счетчик
	}


	// смотрим на диагонали... Если ли там свободные позиции для победы
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

	// если ничего не нашлось, то возвращем -2
	return -2;
}

/// <summary>
/// Находим угол для победы 
/// </summary>
/// <param name="positionCorners"></param>
/// <param name="symbolUser"></param>
/// <param name="symbolAI"></param>
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

// Поиск пустой ячейки
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

/// <summary>
/// Возможные ходы ПК
/// </summary>
/// <param name="positionCorners"></param>
void AITurn(int positionCorners[4], int symbolUser, int symbolAI)
{
	int position;

	// Проверяем есть ли линия из двух позиций
	position = GetPositionForWin(symbolAI);
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	// Проверяем есть ли линия из двух позиций у противника
	position = GetPositionForWin(symbolUser);
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	// находим позицию угла для победы
	position = FindBestCorner();
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	// поиск пустой ячейки
	position = FindEmptyCell();
	if(position != -2)
	{
		SetValueOnMap(position, symbolAI);
		return;
	}

	// если ничего не сработало, то выбираем случайны угол
	bool isCorrect = false;
	while(isCorrect == false)
	{
		position = rand() % 3;
		isCorrect = IsEmptyCell(positionCorners[position]);
		SetValueOnMap(positionCorners[position], symbolAI);
	}
}

/// <summary>
/// Выделение памяти под карту
/// </summary>
/// <param name="positionCorners"></param>
void MamoryAlocationForMap()
{
	Map = new int* [SizeMap];
	for(size_t i = 0; i < SizeMap; i++)
	{
		Map[i] = new int[SizeMap];
	}
}

/// <summary>
/// Удалине памяти из под карты
/// </summary>
/// <param name="positionCorners"></param>
void DeleteMap()
{
	for(size_t i = 0; i < SizeMap; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;
}

/// <summary>
/// Метод когда ПК ходит первым
/// </summary>
/// <param name="positionCorners"></param>
void StartGameAIFirst(int positionCorners[4])
{
	int symbolUser = 0;
	int symbolAI = -1;

	MamoryAlocationForMap();
	FillMapDeffoltValue();

	Map[1][1] = -1; // робот ставит крестик в центр
	ShowMap();

	// Ввод пользователя
	int position;
	position = GetUserPosition(); 
	SetValueOnMap(position, symbolUser);

	bool isCorrect = false;
	ShowMap();
	if(position == 2 || position == 4 || position == 6 || position == 8) // Когда пользователь выбирает позицию для проигрыша
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
			SetValueOnMap(position, symbolAI); 
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
				// Ввод робота
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

	DeleteMap();
}

/// <summary>
/// Метод когда пользователь ходим первым
/// </summary>
/// <param name="positionCorners"></param>
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
	if(Map[1][1] != 5) // если центр занят
	{
		while(CheckWin() == false)
		{
			if(isUser == false)
			{
				// Ввод робота
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
		Map[1][1] = symbolAI; // робот ставит в центр
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
				// Ввод робота
				AITurn(positionCorners, symbolUser, symbolAI);
				isUser = false;
			}
			ShowMap();
		}
	}

	DeleteMap();
}

// Меню программы
void ShowMenu()
{
	srand(time(0));
	int positionCorners[] = {1,3,7,9}; // позиции углов для случайного выбора
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
				std::cout << "Первым ходит пользователь.\n";
				StartGameUserFirst(positionCorners);
				break;

			case 2:
				std::cout << "Первым ходит компьютер.\n";
				StartGameAIFirst(positionCorners);
				break;
			case 3:
				isExit = true;
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