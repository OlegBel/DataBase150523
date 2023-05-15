#include "functions.h"

//инициализация данных
void DataInitialization() {
	//создадим временный файл в котором будем хранить информацию, т.е. создадим буфер
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;

	_buf.close();
}

//ввод данных вручную
void DataEntry() {

	//временные переменные
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "Введите количество данных: ";
	cin >> n;

	//открываем буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app);

	if (record) {//проверяем если файл открылся
		record << n << endl;//кол-во элементов которые хотим записать
		
		for (int i = 0; i < n; i++) {
			cout << "Введите данные №1 (Фамилия): ";
			cin >> _surname;

			cout << "Введите данные №2 (Номер телефона): ";
			cin >> _phoneNum;

			cout << "Введите данные №3 (Город): ";
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1) //проверка на последнюю строку
				record << _city << endl;
			else 
				record << _city;
			
			cout << "____________________" << endl;//отступ в консоли
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();//закрытие файла
}

//чтение данных из файла
void DataReading(string fileName) {
	ifstream reading(fileName);//читает данные
	ofstream record("Buffer.txt", ios::out);//записывает д.

	if (reading) {//проверка на открытие файла
		if (record) {
			//временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			//считываем данные из файла
			reading >> n;//вводим кол-во элементов кот.нужно считать
			record << n << endl;

			//n это кол-во элементов кот.нужно считать
			for (int i = 0; i < n; i++) {
				//сново считали
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				//сново записали
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1) 
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные считаны" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрытие файла
	reading.close();
	record.close();
}

//вывод данных
void Print() {
	ifstream reading("Buffer.txt");//читает данные
	//если файл открылся то...
	if (reading) {
		//временные переменные
		string _surname;
		int _phoneNum;
		string _city;
		int n;
		//считываем временные переменные
		reading >> n;
		cout << "Количество данных: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "Данные об № " << i + 1 << endl;

			reading >> _surname;
			cout << "Данные №1 (Фамилия): " << _surname << endl;

			reading >> _phoneNum;
			cout << "Данные №2 (Номер телефона): " << _phoneNum << endl;

			reading >> _city;
			cout << "Данные №3 (Город): " << _city << endl;

			cout << "________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//закрытие файла
	reading.close();
}

//очистка буфера
bool DataCleaning() {

	bool clear = false;

	//открываем файл
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "Ошибка открытия буферного файла!" << endl;

	//очищаем(снова)
	_buf.clear();

	//проверка что файл чист
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

//изменение данных
void DataChange() {
	//сохраняем еще раз данные
	//очистим буфер и снова записываем данные в него
	//дойдем до необходимого и изменим его данные

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;

			cout << "Выберете номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {
						cout << "Введите данные № 1 (Фамилия): ";
						cin >> _surname;

						cout << "Введите данные № 2 (Номер телефона): ";
						cin >> _phoneNum;

						cout << "Введите данные № 3 (Город): ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}

				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//копирование в новый файл
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			//считываем из буферного файла в новый
			reading >> n;//вводим кол-во элементов кот.нужно считать
			record << n << endl;

			//n это кол-во элементов кот.нужно считать
			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1) 
					record << _city << endl;
				else 
					record << _city;
			}
		}
		else 
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();
}

int AmountOfData() {
	//выводит кол-во данных из файла
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
		_buf >> n;
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.close();

	return n;
}

void DeleteData() {
	//удаление данных
	//запоминаем данные
	//перезаписываем в исходный буфер кроме удаленного

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			//считываем из буферного файла в новый
			reading >> n;
			int b = n - 1;

			cout << "Выберете номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void AddData() {
	
	//временные переменные
	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;

	//открываем буферный файл
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);
	//записываем в начало
	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	//записываем в конец файла
	if (record) {
		record << endl;

		cout << "Введите данные № 1 (Фамилия): ";
		cin >> _surname;

		cout << "Введите данные № 2 (Номер телефона): ";
		cin >> _phoneNum;

		cout << "Введите данные № 3 (Город): ";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName) {
	//cохрание данных

	ifstream reading("Buffer.txt");//поток для чтения нашего буфера
	ofstream record(fileName, ios::out);//поток для записи куда собираемся записать

	//проверка на открытие
	if (reading) {
		if (record) {
			//временные переменные
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;//считываем из нашего буфера во времен.переменные
			record << n << endl;//из времен.пер.записываем куда нужно было сохранить данные

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}

			cout << "Данные сохранены в файле " << fileName << endl;
		}
		else
			cout << "Ошибка открытия буферного файла!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	reading.close();
}
