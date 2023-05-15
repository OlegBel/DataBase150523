// DataBase1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберете действие:" << endl
	<< "(0) Выход из программы." << endl
	<< "(1) Ввод данных." << endl
	<< "(2) Вывод данных." << endl
	<< "(3) Изменение данных." << endl
	<< "(4) Удаление данных." << endl
	<< "(5) Добавление данных." << endl
	<< "(6) Сохранение данных." << endl
	<< "Ваш выбор: ";
	cin >> _stateMenu;
}

/*
	Данные:
	*Фамилия
	*Номер телефона
	*Адрес
*/

void main()
{
	//руссификация консоли ввода/вывода
	SetConsoleCP(1251);//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);//установка кодовой страницы win-cp 1251 в поток вывода

	//setlocale(LC_ALL, "Russian");

	DataInitialization();

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0) {
		switch (_stateMenu) {
		case 1:
			system("cls");//очистка консоли
			
			cout << "Ввод вручную (1) или из файла (любое число кроме 1)?: ";
			cin >> _actions;

			system("cls");//очистка консоли

			if (_actions == 1) {
				DataEntry();//ввод вручную
			}
			else {
				//чтение из файла
				cout << "Введите название файла: ";
				cin >> fileName;
				
				DataReading(fileName);
			}

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////
		case 2:
			system("cls");

			Print();

			system("pause");
			system("cls");
			Menu();
			break;
		//////////////////////////////////////
		case 3:
			system("cls");

			DataChange();

			system("pause");
			system("cls");
			Menu();
			break;
		//////////////////////////////////////
		case 4:
			system("cls");

			DeleteData();

			system("pause");
			system("cls");
			Menu();
			break;
		//////////////////////////////////////
		case 5:
			system("cls");

			AddData();

			system("pause");
			system("cls");
			Menu();
			break;
		//////////////////////////////////////
		case 6:
			system("cls");

			//запись в файл
			cout << "Введите название файла: ";
			cin >> fileName;

			system("cls");

			SaveData(fileName);

			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		//////////////////////////////////////
		default:
			cout << "Неправильно выбран пункт меню!" << endl;
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			Menu();
			break;
		}
		
	}

	system("cls");
	if (DataCleaning())
		cout << "Данные очищены!" << endl;
	else
		cout << "Данные НЕ очищены!" << endl;
	
	cout << "Работа завершена." << endl;
	system("pause");
}
