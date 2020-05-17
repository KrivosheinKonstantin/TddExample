#pragma once
#include <iostream>
using namespace std;

class Indexer
{
private:
	double* arr;
	int start; // начальная позиция
	int length;//размер

	bool Index(int);//корректный индекс

public:
	Indexer(double*, int, int, int);//конструктор
	int Length();//размер массива
	double& operator[] (int);//обращение к переменным
};

Indexer::Indexer(double* _arr, int _start, int _length, int arrLength)
{
	if (_start < 0 || _length <= 0 || _start + _length >= arrLength)
		throw invalid_argument("Error");
	arr = _arr;
	start = _start;
	length = _length;
}

int Indexer::Length()
{
	return length;
}

bool Indexer::Index(int index)
{
	if (index < 0 || index >= Length())
		return false;
	else
		return true;
}

double& Indexer::operator[] (const int i)
{
	if (!Index(i))
		throw out_of_range("Error");
	else
		return arr[i + start];
}