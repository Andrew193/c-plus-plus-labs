#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Line
{
public:
	Line(float x1, float x2, float x3, float y1, float y2, float y3);
	Line();
	Line(float x1, float x2, float x3, float y1, float y2);
	~Line();
	Line(Line& Obg);
	float GetDist();
	float GetDistShort();
	void setPoint(float x1, float x2, float x3, float y1, float y2, float y3);
	void showPoint();
private:
	void FindDistShort();
	void FindDist();
	float M_dist=0;
	float M_distShort = 0;
    float  m_x1;
	float m_x2;
    float m_x3;
	float m_y1;
	float m_y2;
	float m_y3;
};

