#pragma once
#include "stdafx.h"
#include "SimpleTimer.h"


int Sedgewick(long inc[], long size)
{
	int s = 1;
	inc[0] = 1;
	while (3 * inc[s - 1] < size)
		s++ % 2 ? inc[s - 1] = 9 << s - 9 << (s / 2) + 1 : inc[s - 1] = 8 << s - 6 << ((s+1) / 2) + 1;

	return s > 0 ? s - 1 : 0;
}

int FirstKnutIncrement(long inc[], long size)
{
	int h = 0;
	int s = -1;

	do {
		++s;
		inc[s] = 3 * h + 1;
		h = inc[s];
	} while (3 * inc[s] < size);

	return s > 0 ? s : 0;
}

int SecondKnutIncrement(long inc[], long size)
{
	int h = 0;
	int s = -1;

	do {
		++s;
		inc[s] = 2 * h + 1;
		h = inc[s];
	} while (3 * inc[s] < size);

	return s > 0 ? s : 0;
}

template<typename T>
void ShellSort(T* arr, int size, int flag)
{
	int increments, numberOfIncrements, i, j;
	long *arrOfIncrements = new long[20];

	flag == 1 ? numberOfIncrements = FirstKnutIncrement(arrOfIncrements, size) :
	flag == 2 ? numberOfIncrements =	 SecondKnutIncrement(arrOfIncrements, size) : numberOfIncrements = Sedgewick(arrOfIncrements, size); 
		
	while (numberOfIncrements >= 0) {
		//��������� �� ������� ��������� ����������
		increments = arrOfIncrements[numberOfIncrements--];
		// ���������� ��������� � ������������ inc
		for (i = increments; i < size; i++) {
			T temp = arr[i];
			// �������� �������� �� ��� ���, ���� �� ������ �� ����� ��� �� ���������� � ������ �������
			for (j = i - increments; (j >= 0) && (arr[j] > temp); j -= increments)
				arr[j + increments] = arr[j];
			// ����� ���� ������� ������ �� ����� j+inc �������, ������� ��������� �� i �����
			arr[j + increments] = temp;
		}
	}

	delete[] arrOfIncrements;
}