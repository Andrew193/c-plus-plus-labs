#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include<algorithm>
using namespace std;
const int length = 25;
#pragma pack(push, 1)
struct tovar {
	char name[length];
	int price;
	int amount;
	int toGet;
};
#pragma pack(pop)
tovar arr[length];
tovar arr_out[length];
int index = 0;
int menu();
void read(string fileName);
void save(string fileName);
void addNew();
void del();
void sort(tovar *obg2, int number);
void str();
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	while (1) {
		switch (menu()) {
		case 1:
			read("infile.dat");
			break;
		case 2:
			save("infile.dat");
			break;
		case 3:
			addNew();
			break;
		case 4:
			del();
			break;
		case 5:
			return 0;
		case 6:
			str();
			break;
			if (index > 2)
			{
		case 7:
			sort(arr, index);
			break;
			}
		default:
			cout << "Невірний вибір" << endl;
		}
	}
}
int menu()
{
	cout << "\n";
	int ans;
    cout << "Оберіть\n";
	cout << "1-для зчитування з файла\n";
	cout << "2-для запису в файл\n";
	cout << "3-для додавання запису\n";
	cout << "4-для видалення запису\n";
	cout << "5-для виходу\n";
	cout << "6-для зміни запису\n";
	cout << "7-для сортування\n";
	cout << "\n";
	cout << "Ваш вибір ";
	cin >> ans;
	return ans;
}
void save(string fileName)
{
	ofstream f;
	f.open(fileName, ios::binary);
	f.write((char*)arr, sizeof(tovar) * index);
	f.close();
	cout << "Введені дані збережено до файлу\n";
}
void read(string fileName)
{
	ifstream f;
	f.open(fileName, ios::binary);
	if (!f) {
		cout << "Файлу не існує";
	}
	else {
		tovar workr;
		index = 0;
		while (1) {
			f.read((char*)&workr, sizeof(workr));
			if (f.eof())
				break;
			arr_out[index] = workr;
			index++;
		}
		f.close();
		cout << "Дані зчитано з файлу\n";
		for (int i = 0; i < index; i++) {
			cout << i + 1 << "\t" << arr_out[i].name << "\t" << arr_out[i].price <<"\t"<<arr_out[i].amount<<"\t"<<arr_out[i].toGet<<endl;//l
		}
	}
}
void addNew()
{
	cout << "Додавання нового запису\n\n";
	cout << "Запис номер " << index + 1 << "\n";
	cin.ignore();
	cout << "Введіть ПІБ ";
	cin.getline(arr[index].name, length);
	cout << "Введіть вік ";
	cin >> arr[index].price;
	cout << "Введите количество ";
	cin >> arr[index].amount;
	cout << "Введите время доставки ";
	cin >> arr[index].toGet;
	/*if (index >= 2)
	{
		sort(arr, index);
	}*/
	index++;
	cout << "\n";
	for (int i = 0; i < index; i++) {
		cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].price << "\t" << arr[i].amount << "\t" << arr[i].toGet << endl;
	}
	cout << "\n";
}
void str()
{
	int n = 0;
	cout << "Який запис змінити\n";
	cin >> n;
	cout << n << "\t" << arr[n].name << "\t" << arr[n].price << "\t" << arr[n].amount << "\t" << arr[n].toGet << endl;
	cout << "Введіть нові данні.\n";
	cout << "Зміна запису номер " << n << "\n";
	cin.ignore();
	cout << "Введіть ПІБ ";
	cin.getline(arr[n].name, length);
	cout << "Введіть вік ";
	cin >> arr[n].price;
	cout << "Введите количество ";
	cin >> arr[n].amount;
	cout << "Введите время доставки ";
	cin >> arr[n].toGet;
}
void sort(tovar *obg2, int number)
{
	/*cout << "QWERTY";*/
	for (int i = 0; i<number;i++)
	{
		for (int j = 0; j < number - 1; j++)
		{
			if (strcmp(obg2[j].name, obg2[j+1].name)>0)
			{
				/*cout << "QQQQ";*/
				swap(obg2[j], obg2[j + 1]);
			}
		}
	}
	for (int i = 0; i < index; i++) {
		cout << i + 1 << "\t" << obg2[i].name << "\t" << obg2[i].price << "\t" << obg2[i].amount << "\t" << obg2[i].toGet << endl;
	}
}
void del()
{
	int d;
	cout << "Оберіть номер запису, який необхідно видалити ";
	cin >> d;
	for (int i = d - 1; i < index; i++) {
		arr[i] = arr[i + 1];
		index--;
	}
	cout << "\n";
	for (int i = 0; i < index; i++) {
		cout << i + 1 << "\t" << arr[i].name << "\t" << arr[i].price <<"\t"<<arr[i].amount<<"\t"<<arr[i].toGet<< endl;
	}
	cout << "\n";
}
