#include "LinearEquation.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int LinearEquation::Size()
{
	return coef.size();
}


LinearEquation::LinearEquation(string _s)
{
	vector<string> arr = Resplit(_s, "[^\\d-.]");//любой символ кроме цифр, - и .
	for (int i = 0; i < arr.size(); i++)//преобразуем строку в число с плавающей точкой типа double
		if (arr[i] != "") coef.push_back(stod(arr[i].c_str()));
		
}

LinearEquation::LinearEquation(list<double>a)
{ //коэф из списка добавляем в конец вектора
	copy(a.begin(), a.end(), back_inserter(coef));
}
LinearEquation::LinearEquation(vector<double>a)
{
	coef = a;
}
LinearEquation::LinearEquation(int n)
{
	if (n > 0)
		coef.resize(n + 1);
	else throw invalid_argument("Error");
}

void LinearEquation::RandomIn()
{
	//каждый элемент становится равен рандомному значению
	for_each(coef.begin(), coef.end(), [](double& i) {
		i = (rand() % 5) / 10.0; });
}

void LinearEquation::SameIn(double item)
{
	//каждый элемент становится равен item
	for_each(coef.begin(), coef.end(), [item](double& i) {i = item; });
}
double& LinearEquation::operator[](int index)
{
	if (index >= 0 && index < coef.size())
		return coef.at(index);
	else
		throw out_of_range("Error");
}

LinearEquation LinearEquation::operator*(const double& r)
{//уравнение * r
	vector<double> arr = coef;
	for_each(arr.begin(), arr.end(), [r](double& i) { i *= r; });
	return
		LinearEquation(arr);
}

LinearEquation operator*(double r, LinearEquation& a)
{//r * уравнение
	return a * r;
}

LinearEquation LinearEquation::operator+(LinearEquation& a)
{
	vector<double> res = coef;
	for (int i = 0; i < Size(); i++)
		res[i] += a[i];
	return
		LinearEquation(res);
}

LinearEquation LinearEquation::operator-(LinearEquation& a)
{
	vector<double> res = coef;
	for (int i = 0; i < Size(); i++)
		res[i] -= a[i];
	return LinearEquation(res);
}

LinearEquation LinearEquation::operator-()
{
	vector<double> res = coef;
	for_each(res.begin(), res.end(), [](double& i) { i = -i; });
	return
		LinearEquation(res);
}
LinearEquation::operator string()
{
	string res = "";
	int i;
	for (i = 0; i < Size() - 2; i++)
		res += (coef[i + 1] >= 0) ? (to_string(coef[i]) + 'x' + to_string((i + 1)) + '+') :
		(to_string(coef[i]) + 'x' + to_string((i + 1)));
	res += (to_string(coef[i]) + 'x' + to_string((i + 1)));
	res += '=' + to_string(coef[Size() - 1]);
	return res;
}
LinearEquation::operator bool()
{
	for (int i = 0; i < Size() - 1; i++)
		if (coef[i] != 0)
			return true;
	return (coef[Size() - 1] != 0) ? false : true;
}

LinearEquation::operator list<double>() //копируем элементы вектора в список
{
	list<double> coeff;
	copy(coef.begin(), coef.end(), back_inserter(coeff));
	return coeff;
}
bool LinearEquation::IsNull()//проверка эл. на равенство с 0
{
	for (int i = 0; i < Size(); i++)
		if (coef[i] != 0) return false;
	return true;
}

bool operator==(LinearEquation& a, LinearEquation& b)
{
	for (int i = 0; i < a.Size(); i++)
		if (abs(a[i] - b[i]) > 1e-9) return false;
		//из-за ошибок связанных с внутренним двоичным представлением чисел
		//если разница меньше 1x10^(-9) то считаем что равны
	return true;
}
bool operator!=(LinearEquation& a, LinearEquation& b)
{
	if (a == b) return false;
	else return true;
}

vector<string> LinearEquation::Resplit(const string& s, string rgx_str)
{ //разбиваем строку по регулярному выражению
	vector<string> elems;//строки с коэф.
	regex rgx(rgx_str);//регулярное выражение
	sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
	//от начала до конца строки
	//извлекаем элементы, используя начальную строку и регулярное выражение
	//индекс -1 представляет части, которые не совпадают с рег. выражением
	sregex_token_iterator end;
	
	for (sregex_token_iterator i = iter; i != end; ++i)
		elems.push_back(*i); //добавляем найденные элементы
	
	return elems;
}