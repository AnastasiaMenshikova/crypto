// Enigma1.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream> 
#include "Enigma.h"
using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	string input = "fdsf";
	while (input != "q" || input != "Q")
	{
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
		}
		else if (input == "2")
		{
			machine.setRings(plugz);
			machine.defaultPlugs(false);
			machine.defaultRotors(false);
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
				string msg;
				getline(cin, msg);
				string e = machine.Encrypt(msg);
				cout << "Зашифрованное сообщение: " << e << endl;
				cout << "Введите D, чтобы попытаться расшифровать сообщение." << endl;
				cout << "Введите P, чтобы посмотреть путь шифрования." << endl;
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
			}
			else if (input == "V" || input == "v")
				machine.printRotorSettings();
			else if (input == "P" || input == "p")
				machine.printPlugBoard();
			else if (input == "q" || input == "Q")
				cout << "Выход из приложения..." << endl;
		}
	}
	return 0;
}
