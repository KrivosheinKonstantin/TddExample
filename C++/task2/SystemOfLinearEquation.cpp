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
	if (a.Size() - 1 == n) //если можно добавить => добавляем в конец
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
		if (SLE[i][z] == 0)//если элемент на главной диагонали равен 0
		{
			while (SLE[i][z] == 0 && z < n) z++;
			m = 1;//поиск нулевого элемента в столбцах строки
			while ((i + m) < Size() && SLE[i + m][z] == 0)
				m++;//поиск нулевого элемента в столбце нижних строк
			if ((i + m) == Size())//имеет ступенчатый вид
				return;
			swap(SLE[i], SLE[i + m]);//опускаем строку вниз
		}//нормализация уравнений
		for (int j = i + 1; j < Size(); j++)
		{
			LinearEquation tmp1 = SLE[j] * SLE[i][z];
			LinearEquation tmp2 = SLE[i] * SLE[j][z];
			SLE[j] = tmp1 - tmp2;
			//элементарными преобразованиями приравнием коэф переменных у 
			//нижних уравнений к 0
		}
	}
}
vector<double> SystemOfLinearEquation::Solve()
{
	while (SLE[Size() - 1].IsNull())//удаляем 0 строки
		SLE.pop_back(); // 
	if (SLE[Size() - 1])//если СЛУ не пуста. Иначе Нет решений
	{
		if (Size() == n)
		{//переменных столько же сколько строк. Иначе Бесконечно много решений
			vector<double> solve(n);
			for (int i = Size() - 1; i >= 0; i--)
			{
				solve[i] = SLE[i][n];// = свободному эллементу
				for (int j = i + 1; j < n; j++)
					solve[i] -= SLE[i][j] * solve[j];//вычитаем уже найденные элементы
				solve[i] /= SLE[i][i];//делим свободный элемент на коэф. неизвестной переменной
			}
			return solve;
		}
		else throw invalid_argument("Решений бесконечно много");
	}
	else throw invalid_argument("Нет решений");
}
SystemOfLinearEquation::operator string()
{
	string res = "";
	for (int i = 0; i < Size(); i++)
		res += (string)SLE[i] + '\n';
	return res;
}