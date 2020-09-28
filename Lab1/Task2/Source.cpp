/*
Написать программу, которая преобразует одномерный массив (1D) в двумерный (2D)
(или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
функциях код следующих действий: 1) инициализация массива; 2) вывод массива; 3)
преобразование массива (создание нового массива с другой структурой). Память под
массивы выделять динамически и для доступа к элементам использовать указатели.
Ввод-вывод данных организовать средствами iostream и iomanip

Вариант 3

Преобразование: 2D → 1D. Двумерный массив 4х4 вещественных чисел необходимо
выложить в один ряд по элементам справа налево и сверху вниз.
Инициализация: заполнить массив числами x[i][j] = √(i+j+1).
Вывод на экран: каждый элемент одномерного массива вывести с точностью 4 знака
после запятой; каждый элемент двумерного массива – с точностью 2 знака.
[ 1 1.41 1.73 2
 1.41 1.73 2 2.24
 1.73 2 2.24 2.45
 2 2.24 2.45 2.65 ]
=>
[ 2 1.7321 1.4142 1 2.2361 2 1.7321 1.4142 2.4495 2.2361 2 1.7321 2.6458
 2.4495 2.2361 2 ]

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>

void fillingTheArray(double** first2D);
void printTheArray2D(double** first2D);
void makeArray1D(double** first2D, double* second1D);

int main()
{
	double** first2D = new double* [4]; 

	for (int i = 0; i < 4; i++) // Создание динамического двумерного массива
	{
		*(first2D + i) = new double [4];
	}

	double* second1D = new double [16]; //Объявление динамеческого одномерного массива

	fillingTheArray(first2D);

	printTheArray2D(first2D);

	makeArray1D(first2D, second1D);


}

void fillingTheArray(double** first2D) // Функция заполнения массива
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			*(*(first2D + i) + j) = sqrt(i + j + 1);
		}
	}
}

void printTheArray2D(double** first2D) // Фунция вывода двумерного массива
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << std::setprecision(3) << *(*(first2D + i) + j) << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void makeArray1D(double** first2D, double* second1D)
{	
	int cnt = 0;
	for (size_t i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			*(second1D + cnt) = *(*(first2D + i) + j);
			cnt++;
		}
	}

	for (size_t i = 0; i < 16; i++)
	{
			std::cout << std::setprecision(5) << *(second1D + i) <<" ";
	}
}