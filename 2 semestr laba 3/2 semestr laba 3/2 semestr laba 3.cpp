// 2 semestr laba 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<ctime>
#include<iomanip>
#include"Header1.h"
using namespace std;
int SetSize()
{
	int a = 0;
	bool flag = false;
	do
	{
		cin >> a;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(33000, '\n');
		}
		else flag= true;
	} while (!flag);
	return a;
}
void foo(int *a, int *b, float **Array)
{
	bool flag = false;
start:
	if (flag)
		cout << "Некоректный ввод";
	cout << "Задать значения самому 1, автоматически 2.";
	int des;
	des=SetSize();
	if (des < 1 || des>2)
	{
		flag = true;
		goto start;
	}
	else
	{
		switch (des)
		{
		case 1:
		{
			for (int i = 0; i < *a; i++)
				for (int j = 0; j < *b; j++)
					cin >> Array[i][j];
			break;
		}
		case 2:
		{
			for (int i = 0; i < *a; i++)
				for (int j = 0; j < *b; j++)
					Array[i][j]=1+rand()%10-1;
			break;
		}
		default:
			break;
		}
	}

}
int Oper()
{
	int a;
	cout << "Заполнить матрицу 1\n";
	cout << "Показать матрицу 2\n";
	cout << "Транспонировать матрицу 3\n";
	cout << "Умножить каждый элемент матрицы на число 4\n";
	cout << "Поделить каждый элемент матрицы на число 5\n";
	cout << "Отзеркалить относительно побочной  диагонали 6\n";
	cout << "Выход 7\n";
	cout << "Изменить положение строк 8\n";
	cout << "Получить значение количества строк 9\n";
	cout << "Получить значение количества столбцов 10\n";
	cout << "Изменить элементы 11\n";
	cin >> a;
	return a;
}
int main()
{
	srand(time(0));
	setlocale(0, "");
	cout << "Введите размерность матрицы\n";
	int a=SetSize();
	int b=SetSize();
	_Matrix_ first(a, b);
	//new mass
	float** TempMatrix = new float* [a];
	for (int i = 0; i < a; i++)
		TempMatrix[i] = new float[b];
	//end
	first._Creat_Mass_(a, b);
	first._Show_Size_();
	while (true)
	{
		switch (Oper())
		{
		case 1:
		{
			first._Fill_Mass_();
			break;
		}
		case 2:
		{
			first._Show_Mass_();
			break;
		}
		case 3:
		{
			first._Transform_Mass_();
			break;
		}
		case 4:
		{
			first._Mult_Mass_();
			break;
		}
		case 5:
		{
			first._Del_Mass_();
			break;
		}
		case 6:
		{
			first._Mir_Mass_();
			break;
		}
		case 7:
		{
			first._Close_Mass_();
			break;
		}
		case 8:
		{
			first._Change_Position_Mass_();
			break;
		}
		case 9:
		{
			cout<<first._Get_M_Size_Of_Str()<<"\n";
			break;
		}
		case 10:
		{
			cout << first._Get_M_Size_Of_Stl()<<"\n";
			break;
		}
		case 11:
		{
			cout << "Введите новые значения матрицы\n";
			foo(&a,&b,TempMatrix);
			first._Set_Matrix_(TempMatrix);
		}
		default:
			break;
		}
	}
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
