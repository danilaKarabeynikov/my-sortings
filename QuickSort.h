#pragma once
#include <stack>
#include "stdafx.h"
#include "SimpleTimer.h"
#define MAXSTACK 2048 // ������������ ������ �����

template<class T>
void QuickSort(T arr[], long size) {

	long i, j; // ���������, ����������� � ����������
	long leftBorder, rightBorder; // ������� ������������ � ����� ���������
	long leftStack[MAXSTACK], rightStack[MAXSTACK]; // ���� ������ ����������
	long stackPosition = 1; // ������� ������� �����
	long middle; // �������� �������
	T median; // ������� �������
	T variable;

	leftStack[1] = 0;
	rightStack[1] = size - 1;

	do 
	{
		// ����� ������� �������� ������� �� �����.
		leftBorder = leftStack[stackPosition];
		rightBorder = rightStack[stackPosition];
		stackPosition--;

		do 
		{
			// ���������� �� �������� median
			middle = (leftBorder + rightBorder) >> 1;	// ������� �������� � ����� ������� ������� ���������
			i = leftBorder;
			j = rightBorder;
			median = arr[middle];
			do {
				while (arr[i] < median)
					i++;

				while (median < arr[j])
					j--;

				if (i <= j) 
				{
					variable = arr[i];
					arr[i] = arr[j];
					arr[j] = variable;
					i++; j--;
				}
			} while (i <= j);

			// ������ ��������� i ��������� �� ������ ������� ����������,
			// j - �� ����� ������ (��. ����������� ����), leftBorder ? j ? i ? rightBorder.
			// �������� ������, ����� ��������� i ��� j ������� �� ������� �������

			// ���� 2, 3. ���������� ������� ����� � ���� � ������� leftBorder,rightBorder
			if (i < middle) { // ������ ����� ������
				if (i < rightBorder) { // ���� � ��� ������ 1 �������� - �����
					stackPosition++; // �����������, ������ � ����
					leftStack[stackPosition] = i;
					rightStack[stackPosition] = rightBorder;
				}
				rightBorder = j; // ��������� �������� ����������
				// ����� �������� � ����� ������
			}
			else { // ����� ����� ������
				if (j > leftBorder) {
					stackPosition++;
					leftStack[stackPosition] = leftBorder;
					rightStack[stackPosition] = j;
				}
				leftBorder = i;
			}
		} while (leftBorder < rightBorder); // ���� � ������� ����� ����� 1 ��������
	} while (stackPosition != 0); // ���� ���� ������� � �����
}