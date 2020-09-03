﻿// 2 semestr 4 laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Header1.h"
using namespace std;
void ToDo(Line &Obg);
int menu();
int main()
{
	float x1, x2, x3, y1, y2, y3;
	setlocale(0, "");
		cout << "Вводите координаты вершин ломаной линии. Сначала y1-x3, а потом y1-y3.\n";
		cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
		Line line1(x1, x2, x3, y1, y2,y3);//параметры
		Line line2(x1, x2, x3, y1, y2);//список
		Line line3;//stok
		Line line4 = line1;//cop
		line1.~Line();
		ToDo(line1);
}
void ToDo(Line &Obg)
{
	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			cout << "Расстояние составляет-" << Obg.GetDist()<<"\n";
			break;
		}
		case 2:
		{
			cout << "Расстояние составляет-" << Obg.GetDistShort() << "\n";
			break;
		}
		case 3:
		{
			Obg.showPoint();
			float x1, x2, x3, y1, y2, y3;
			cout << "Вводите х от х1 до х3.\n";
			cin >> x1 >> x2 >> x3;
			cout << "Вводите у от у1 до у3.\n";
			cin >> y1 >> y2 >> y3;
			Obg.setPoint(x1, x2, x3, y1, y2, y3);
		}
		default:
			break;
		}
	}
}
int menu()
{
	int number;
	cout << "Выберите операцию.\n";
	cout << "Узнать растояние от начала и до конца ломаной(все звенья) 1.\n";
	cout << "Узнать самое короткое растояние 2.\n";
	cout << "Изменить координаты 3.\n";
	cin >> number;
	return number;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.