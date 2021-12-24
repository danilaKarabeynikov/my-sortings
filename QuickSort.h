#pragma once
#include <stack>
#include "stdafx.h"
#include "SimpleTimer.h"
#define MAXSTACK 2048 // максимальный размер стека

template<class T>
void QuickSort(T arr[], long size) {

	long i, j; // указатели, участвующие в разделении
	long leftBorder, rightBorder; // границы сортируемого в цикле фрагмента
	long leftStack[MAXSTACK], rightStack[MAXSTACK]; // стек границ промежутка
	long stackPosition = 1; // текуща€ позици€ стека
	long middle; // середина массива
	T median; // опорный элемент
	T variable;

	leftStack[1] = 0;
	rightStack[1] = size - 1;

	do 
	{
		// Ѕерем границы текущего массива из стека.
		leftBorder = leftStack[stackPosition];
		rightBorder = rightStack[stackPosition];
		stackPosition--;

		do 
		{
			// –азделение по элементу median
			middle = (leftBorder + rightBorder) >> 1;	// Ќаходим середину и делим пополам битовым смещением
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

			// —ейчас указатель i указывает на начало правого подмассива,
			// j - на конец левого (см. иллюстрацию выше), leftBorder ? j ? i ? rightBorder.
			// ¬озможен случай, когда указатель i или j выходит за границу массива

			// Ўаги 2, 3. ќтправл€ем большую часть в стек и двигаем leftBorder,rightBorder
			if (i < middle) { // права€ часть больше
				if (i < rightBorder) { // если в ней больше 1 элемента - нужно
					stackPosition++; // сортировать, запрос в стек
					leftStack[stackPosition] = i;
					rightStack[stackPosition] = rightBorder;
				}
				rightBorder = j; // следующа€ итераци€ разделени€
				// будет работать с левой частью
			}
			else { // лева€ часть больше
				if (j > leftBorder) {
					stackPosition++;
					leftStack[stackPosition] = leftBorder;
					rightStack[stackPosition] = j;
				}
				leftBorder = i;
			}
		} while (leftBorder < rightBorder); // пока в меньшей части более 1 элемента
	} while (stackPosition != 0); // пока есть запросы в стеке
}