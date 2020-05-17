#include "SystemOfLinearEquation.h"
#include<stdexcept>
using namespace std;

LinearEquation& SystemOfLinearEquation::operator[](int index)
{
	if (index >= 0 && index < SLE.size())
		return SLE[index];
	else throw out_of_range("Error");
}
int SystemOfLinearEquation::Size()
{
	return SLE.size();
}

void SystemOfLinearEquation::Add(LinearEquation& a)
{
	if (a.Size() - 1 == n) //���� ����� �������� => ��������� � �����
		SLE.push_back(a);
	else throw invalid_argument("Error");
}
void SystemOfLinearEquation::Delete() 
{ 
	SLE.pop_back(); 
}

void SystemOfLinearEquation::StepView()
{
	int m, z;
	for (int i = 0; i < Size(); i++)
	{
		z = i;
		if (SLE[i][z] == 0)//���� ������� �� ������� ��������� ����� 0
		{
			while (SLE[i][z] == 0 && z < n) z++;
			m = 1;//����� �������� �������� � �������� ������
			while ((i + m) < Size() && SLE[i + m][z] == 0)
				m++;//����� �������� �������� � ������� ������ �����
			if ((i + m) == Size())//����� ����������� ���
				return;
			swap(SLE[i], SLE[i + m]);//�������� ������ ����
		}//������������ ���������
		for (int j = i + 1; j < Size(); j++)
		{
			LinearEquation tmp1 = SLE[j] * SLE[i][z];
			LinearEquation tmp2 = SLE[i] * SLE[j][z];
			SLE[j] = tmp1 - tmp2;
			//������������� ���������������� ���������� ���� ���������� � 
			//������ ��������� � 0
		}
	}
}
vector<double> SystemOfLinearEquation::Solve()
{
	while (SLE[Size() - 1].IsNull())//������� 0 ������
		SLE.pop_back(); // 
	if (SLE[Size() - 1])//���� ��� �� �����. ����� ��� �������
	{
		if (Size() == n)
		{//���������� ������� �� ������� �����. ����� ���������� ����� �������
			vector<double> solve(n);
			for (int i = Size() - 1; i >= 0; i--)
			{
				solve[i] = SLE[i][n];// = ���������� ���������
				for (int j = i + 1; j < n; j++)
					solve[i] -= SLE[i][j] * solve[j];//�������� ��� ��������� ��������
				solve[i] /= SLE[i][i];//����� ��������� ������� �� ����. ����������� ����������
			}
			return solve;
		}
		else throw invalid_argument("������� ���������� �����");
	}
	else throw invalid_argument("��� �������");
}
SystemOfLinearEquation::operator string()
{
	string res = "";
	for (int i = 0; i < Size(); i++)
		res += (string)SLE[i] + '\n';
	return res;
}