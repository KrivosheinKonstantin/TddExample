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
	int Size();//���-�� ���������
	LinearEquation(string);//������ � �����.
	LinearEquation(list<double>);//������
	LinearEquation(vector<double>);//������
	LinearEquation(int);//n ��������� � 0�����.
	~LinearEquation() {
		vector<double>().swap(coef);
	};
	void RandomIn();//������������� ���������� �������
	void SameIn(double);//����������� ����������
	bool IsNull();//�������� �� �������
	double& operator[] (int);//��������� � ��������� �� �������

	LinearEquation operator+(LinearEquation&);//�������� ���� ���������
	LinearEquation operator-(LinearEquation&);//��������� ���� ���������
	LinearEquation operator-();// ��������� �� -1
	LinearEquation operator*(const double&);//��������� �� ���.�����

	operator string();//�����
	operator bool();//�������� �� ����������������
	operator list<double>();//������� �������������� � ������
	friend LinearEquation operator*(double, LinearEquation&);//��������� �� ���.�����

};
// ������������ ��� ���������
bool operator==(LinearEquation&, LinearEquation&);
bool operator!=(LinearEquation&, LinearEquation&);