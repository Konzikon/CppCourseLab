/*
Написать свой аналог стандартной функции обработки строк из файла cstring, в
соответствии с вариантом. В функции main на тестовых данных продемонстрировать
результат работы как стандартной функции, так и собственной версии. Ввод-вывод
данных организовать средствами cstdio.

Вариант 3

Функция strcat.
Формат char* strcat(char* dest, const char* src).
Функция приписывает строку src к строке dest.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcat(char* dest, const char* src);

int main()
{
	char s1[50] = "random text from s1 ";	// тестовая строка 1
	const char s2[] = "abrakadabra s2";	// тестовая строка 2
	char my_result[50] = { "" };		// переменная для результата моей функции

	char standart_result[50] = {""};	// переменная для результата стандартной функции

	strcpy(standart_result, s1);		// копирование строки s1
	strcpy(my_result, s1);		// копирование строки s1

	strcat(standart_result, s2);		// объединение строк и результат помещается в standart_result

	printf("s1 = %s\n",s1);				// вывод s1 на экран
	printf("s2 = %s\n", s2);			// вывод s2 на экран
	printf("Standart function  = %s\n", standart_result); // вывод результата стандартной функции

	 my_strcat(my_result, s2);
	 printf("My function = %s", my_result);


}

char* my_strcat(char* dest, const char* src)
{
	size_t cnt1 = 0;
	cnt1 = strlen(dest);
	size_t j = 0;
	for (size_t i = cnt1; i < 50; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return dest;
}
