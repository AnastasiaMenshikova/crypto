#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream> 
#include "enigma.h"
using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	string input = "fdsf";
	ifstream f;
	ofstream f1;
	string msg;
	string e, d;

	while (input != "q" || input != "Q")
	{
		int mn;
		Enigma machine = Enigma();
		string plugz;
		cout << "Энигма" << endl;
		cout << "Введите 3 символа (пример: ABC), чтобы установить значения для роторов(справа налево)." << endl;
		getline(cin, plugz);
		while (plugz.length() != 3)
			getline(cin, plugz);
		cout << "Нажмите 1 для полной настройки машины по умолчанию." << endl;
		cout << "Нажмите 2 для случайной настройки машины." << endl;
		getline(cin, input);
		if (input == "1")
		{
			machine.setRings(plugz);
			machine.defaultPlugs(true);
			machine.defaultRotors(true);
			cout << "Настройки завершены." << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
		}
		else if (input == "2")
		{
			machine.setRings(plugz);
			machine.defaultPlugs(false);
			machine.defaultRotors(false);
			cout << "Настройки завершены." << endl;
			system("pause");
			cin.clear();
			cin.ignore();
			system("cls");
		}
		while (input != "n" && input != "q")
		{
			cout << "Введите E, чтобы зашифровать сообщение." << endl;
			cout << "Введите V, чтобы посмотреть настройки ротора." << endl;
			cout << "Введите P, чтобы посмотреть настройки коммутационной панели" << endl;
			cout << "Введите n, чтобы создать новую машину." << endl;
			cout << "Введите q для завершения программы." << endl;
			getline(cin, input);
			if (input == "E" || input == "e")
			{
				cout << "Введите сообщение: " << endl;

				getline(cin, msg);
				e = machine.Encrypt(msg);
				cout << "Зашифрованное сообщение: " << e << endl;
				cout << "Введите D, чтобы попытаться расшифровать сообщение." << endl;
				cout << "Введите P, чтобы посмотреть путь шифрования." << endl;
				cout << "Введите W, чтобы записать в файл." << endl;
				cout << "Введите R, чтобы считать из файла." << endl;

				getline(cin, input);
				if (input == "P" || input == "p")
					machine.printEncrypt();
				cout << "Расшифровать сейчас? Введите D" << endl;
				getline(cin, input);
				if (input == "D" || input == "d")
				{
					string d = machine.Decrypt(e);
					if (d == msg)
						cout << "Успешно!" << endl;
					else
						cout << "Неудалось расшифровать." << endl;
					cout << "Расшифрованное сообщение: " << d << endl;
					cout << "Напечать путь расшифрования? Введите P" << endl;
					getline(cin, input);
					if (input == "P" || input == "p")
						machine.printDecrypt();
				}
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
			}
			else if (input == "V" || input == "v")
			{
				machine.printRotorSettings();
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
			}
			else if (input == "P" || input == "p")
			{
				machine.printPlugBoard();
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
			}
			else if (input == "w" || input == "W")
			{
				cout << "Введите имя файла\n";
				char name_file1[30];
				cin >> name_file1;
				f1.open(name_file1, ios::out | ios::trunc);
				if (!f1.is_open())
				{
					cout << "Ошибка при открытии файла" << endl << endl;
					system("pause");
					cin.clear();
					cin.ignore();
					system("cls");
					break;
				}

			else if (input == "r" || input == "R")
			{
				cout << "Введите имя файла\n";
				char name_file[30];
				cin >> name_file;
				f.open(name_file, ios::in);
				if (!f.is_open())
				{
					cout << "Ошибка!Такого файла не существует, создайте или введите другое название" << endl << endl;
					system("pause");
					cin.clear();
					cin.ignore();
					system("cls");
					break;
				}
				while (!f.eof()) {
					f >> msg;
				}
				f.close();
				cout << "Элементы были считаны из файла" << endl << endl;
				system("pause");
				cin.clear();
				cin.ignore();
				system("cls");
				break;
			}


			else if (input == "q" || input == "Q") 
			{
				cout << "Выход из приложения..." << endl;
				break;
			}
		}
	}
	return 0;
}
