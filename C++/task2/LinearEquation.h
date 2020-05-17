#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <list>
using namespace std;
class LinearEquation
{
private:
	vector<double> coef;
	vector<string> Resplit(const string&, string);
public:
	int Size();//кол-во элементов
	LinearEquation(string);//строка с коэфф.
	LinearEquation(list<double>);//список
	LinearEquation(vector<double>);//массив
	LinearEquation(int);//n перменных с 0коэфф.
	~LinearEquation() {
		vector<double>().swap(coef);
	};
	void RandomIn();//Инициализация случайными числами
	void SameIn(double);//Одинаковыми значениями
	bool IsNull();//проверка на пустоту
	double& operator[] (int);//обращение к элементам по индексу

	LinearEquation operator+(LinearEquation&);//сложение двух уравнений
	LinearEquation operator-(LinearEquation&);//вычитание двух уравнений
	LinearEquation operator-();// умножение на -1
	LinearEquation operator*(const double&);//умножение на вещ.число

	operator string();//вывод
	operator bool();//проверка на противоречивость
	operator list<double>();//неявное преобразование к списку
	friend LinearEquation operator*(double, LinearEquation&);//умножение на вещ.число

};
// конструкторы для сравнения
bool operator==(LinearEquation&, LinearEquation&);
bool operator!=(LinearEquation&, LinearEquation&);