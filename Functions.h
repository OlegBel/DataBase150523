#pragma once

#include <iostream>//библ. ввода вывода
#include <fstream>//библ. чтения записи в/из файл
#include <string>//строки
#include <Windows.h>//для функций system

using namespace std;

//прототипы функций
void DataInitialization();//инициализация данных
void DataEntry();//ввод д. вручную
void DataReading(string fileName);//чтение д.
void Print();//вывод д. в консоль
bool DataCleaning();//очистка д.
void DataChange();//изменение д.
void Copy();//копирование д.
int AmountOfData();//кол-во д.
void DeleteData();//удаление д.
void AddData();//добавление д.
void SaveData(string fileName);//сохранение д.
