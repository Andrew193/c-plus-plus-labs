#include"Header1.h"
Line::Line(float x1=0, float x2=0, float x3=0, float y1=0, float y2=0, float y3=0)
{
	 m_x1=x1;
	 m_x2=x2;
	 m_x3=x3;
	 m_y1=y1; 
     m_y2=y2;
	 m_y3=y3;
	cout << "Сработал конструктор с параметрами.\n";
	cout << "m_x1 " << m_x1 << "  m_x2 " << m_x2 << "  m_x3" << m_x3 << " m_y1 " << m_y1 << "  m_y2 " << m_y2 << "  m_y3 " << m_y3 << "\n";
}
Line::Line()
	: m_x1(1), m_x2(2), m_x3(3), m_y1(1), m_y2(2), m_y3(3)
{
	cout << "m_x1 " << m_x1 << "  m_x2 " << m_x2 << "  m_x3" << m_x3 << " m_y1 " << m_y1 << "  m_y2 " << m_y2 << "  m_y3 " << m_y3 << "\n";
	cout << "Сработал конструктор по умолчанию.\n";
}
Line::~Line() { cout << "Деструктор сработал.\n"; };
void Line::showPoint()
{
	cout << "x1 " << m_x1 << " x2 " << m_x2 << " x3 " << m_x3 << " y1 " << m_y1 << " y2 " << m_y2 << " y3 " << m_y3 << "\n";
}
Line::Line(Line& Obg)
{
	m_x1 = Obg.m_x1;
	m_x2 = Obg.m_x2;
	m_x3 = Obg.m_x3;
	m_y1 = Obg.m_y1;
	m_y2 = Obg.m_y2;
	m_y3 = Obg.m_y3;
	cout << "m_x1 "<< m_x1 << "  m_x2 " << m_x2 << "  m_x3" << m_x3 <<" m_y1 "<< m_y1 << "  m_y2 " << m_y2 << "  m_y3 " << m_y3 << "\n";
	cout << "Копирующая сработала.\n";
}
Line::Line(float x1, float x2, float x3, float y1, float y2) 
	: m_x1(x1), m_x2(x2), m_x3(x3), m_y1(y1), m_y2(y2)
{ 
	float f;
	do
	{
		cin >> f;
		if (f != m_y1 || f != m_y2)
			break;
	} while (true);
	m_y3 = f;
	cout << "m_x1 " << m_x1 << "  m_x2 " << m_x2 << "  m_x3" << m_x3 << " m_y1 " << m_y1 << "  m_y2 " << m_y2 << "  m_y3 " << m_y3 << "\n";
	cout << "Сработал список инициализации.\n"; 
};
void Line::setPoint(float x1 = 0, float x2 = 0, float x3 = 0, float y1 = 0, float y2 = 0, float y3 = 0)
{
	m_x1 = x1;
	m_x2 = x2;
	m_x3 = x3;
	m_y1 = y1;
	m_y2 = y2;
	m_y3 = y3;
	FindDist();
	FindDistShort();
	cout << "Значения изменились.\n";
}
float Line::GetDist()
{ 
	FindDist();
	return M_dist; 
};
void Line::FindDist()
{
	M_dist = sqrt(pow(m_x2 - m_x1, 2) + pow(m_y2 - m_y1, 2)) + sqrt(pow(m_x3 - m_x2, 2) + pow(m_y3 - m_y2, 2));
}
float Line::GetDistShort() 
{ 
	FindDistShort();
	return M_distShort; 
};
void Line::FindDistShort()
{
	M_distShort = sqrt(pow(m_x3 - m_x1, 2) + pow(m_y3 - m_y1, 2));
}