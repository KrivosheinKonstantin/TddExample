#pragma once
#include"LinearEquation.h"
#include<string>
class SystemOfLinearEquation
{
private:
	vector<LinearEquation> SLE;
	int n;//���-�� ����������
public:
	SystemOfLinearEquation(int _n) :n(_n) {}//n ����������
	~SystemOfLinearEquation() { vector<LinearEquation>().swap(SLE); }
	LinearEquation& operator[] (int);//��������� � ��������� �� �������
	int Size();//��������� ���-�� ���������
	void Add(LinearEquation&); //�������� ��������� � ���
	void Delete();//������� ��������� �� ���
	void StepView();//���������� � ������������ ����
	vector<double> Solve();//�������
	operator string();//��������������� ������
};