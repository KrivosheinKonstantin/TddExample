// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "SystemOfLinearEquation.h"
#include "LinearEquation.h"
#include <iostream>
using namespace std;
int main()
{
    
    
    LinearEquation a("-1, 2, 3.4");
    LinearEquation b("-1, 2     3.4");
    a == b;
}


