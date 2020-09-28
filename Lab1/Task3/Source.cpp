/*
�������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
������������ � ���������. � ������� main �� �������� ������ ������������������
��������� ������ ��� ����������� �������, ��� � ����������� ������. ����-�����
������ ������������ ���������� cstdio.

������� 3

������� strcat.
������ char* strcat(char* dest, const char* src).
������� ����������� ������ src � ������ dest.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcat(char* dest, const char* src);

int main()
{
	char s1[50] = "random text from s1 ";	// �������� ������ 1
	const char s2[] = "abrakadabra s2";	// �������� ������ 2
	char my_result[50] = { "" };		// ���������� ��� ���������� ���� �������

	char standart_result[50] = {""};	// ���������� ��� ���������� ����������� �������

	strcpy(standart_result, s1);		// ����������� ������ s1
	strcpy(my_result, s1);		// ����������� ������ s1

	strcat(standart_result, s2);		// ����������� ����� � ��������� ���������� � standart_result

	printf("s1 = %s\n",s1);				// ����� s1 �� �����
	printf("s2 = %s\n", s2);			// ����� s2 �� �����
	printf("Standart function  = %s\n", standart_result); // ����� ���������� ����������� �������

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
