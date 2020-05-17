#pragma once
#include"LinearEquation.h"
#include<string>
class SystemOfLinearEquation
{
private:
	vector<LinearEquation> SLE;
	int n;//кол-во переменных
public:
	SystemOfLinearEquation(int _n) :n(_n) {}//n переменных
	~SystemOfLinearEquation() { vector<LinearEquation>().swap(SLE); }
	LinearEquation& operator[] (int);//обращение к элементам по индексу
	int Size();//возращает кол-во уравнений
	void Add(LinearEquation&); //добавить уравнение в СЛУ
	void Delete();//удалить уравнение из СЛУ
	void StepView();//приведение к ступенчатому виду
	vector<double> Solve();//решение
	operator string();//переопределение метода
};