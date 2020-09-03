#include <fstream>
#include <iostream>
using namespace std;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;

#pragma pack(push,1)
struct BitmapFileHeader
{
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
};
#pragma pack(push,1)
struct BitmapInfoHeader
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
};
void col2(int& s);

// .bmp файл
void CreateBmp(const char* fileName, LONG* colors, int
	height, int width)
{
	BitmapFileHeader bfh = { 0 };
	BitmapInfoHeader bih = { 0 };
	bfh.bfType = 0x4D42; //символи 'BM'
	bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
	bfh.bfSize = bfh.bfOffBits + sizeof(colors[0]) * height * width;
	// роз файлa
	bih.biSize = sizeof(bih); // розм структуры
	bih.biBitCount = 32; //  бит на пиксель
	bih.biHeight = -height; // Высота
	bih.biWidth = width; // Ширина
	bih.biPlanes = 1; // 
	ofstream f;
	f.open(fileName, ios::binary | std::ios::trunc); //записываем
	f.write((char*)&bfh, sizeof(bfh)); // Записываем заголовки
	f.write((char*)&bih, sizeof(bih));
	// Записываем изображение
	f.write((char*)colors, sizeof(colors[0]) * width * height);
	f.close(); // Закрываем файл
}
#pragma pack (pop)
int fill(int col);
int check();
int main(int argc, char* argv[])
{
	setlocale(0, "");
	int h = 0, w = 0;
	cout << "Размер изображения" << endl;
	h = check();
	w = check();
	cout << "Цвет треугольника\n";
	int triangle, background;
	col2(triangle);
	cout << "Цвет фона\n";
	col2(background);
	LONG* color = new  LONG[h * w];
	float aspect = (float)w / h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if ((i <= h / 2) && (j - i * aspect >= 0) && (j - (w - 1 - i * aspect) <= 0))
				color[i * w + j] = fill(triangle);
			else
				color[i * w + j] = fill(background);
		}
	}
	CreateBmp("test.bmp", color, h, w);
	delete[]color;
	cout << "test.bmp has been successfully created; Press Enter to exit";
	cin.ignore(2);//
	return 0;
}
int check()
{
	int number = 0;
	bool flag = false;
	do
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32762, '\0');
		}
		else
			flag = true;
	} while (!flag);
	return number;
}
int fill(int col)
{
	switch (col)
	{
	case 1:
		return 0xFF0000;
		break;
	case 2:
		return 0x008000;
		break;
	case 3:
		return 0xFFFF00;
		break;
	case 4:
		return 0x008080;
		break;
	case 5:
		return 0x0000FF;
		break;
	case 6:
		return 0x808080;
		break;
	default:
		break;
	}
	return 0;
}
void col2(int& s)
{
	int number = 0;
	cout << "Red 1\n";
	cout << "Green 2\n";
	cout << "Yellow 3\n";
	cout << "Teal 4\n";
	cout << "Blue 5\n";
	cout << "Gray 6\n";
	cin >> number;
	s = number;
}