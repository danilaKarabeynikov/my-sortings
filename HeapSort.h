#pragma once
#include "stdafx.h"
#include "SimpleTimer.h"

template <typename T>
void siftDown(T value, size_t root, size_t bottom)
{
	int maxChild;
	
	while (root * 2 <= bottom)
	{
		if (root * 2 == bottom)    // если мы в последнем ряду, то запоминаем левый потомок
			maxChild = root * 2;
		  
		else if (value[root * 2] > value[root * 2 + 1]) // иначе запоминаем больший потомок из двух
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		
		if (value[root] < value[maxChild]) // если элемент вершины меньше максимального потомка, то меняем их местами
		{
			int temp = value[root];
			value[root] = value[maxChild];
			value[maxChild] = temp;
			root = maxChild;
		}
		else
			return;
	}
}

template<typename Y>
void heapSort(Y value, size_t array_size)
{
	// мы формируем наименьшие пирамиды, которые имеют отца и двух сыновей, эти сыновья являются листьями большой пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(value, i, array_size - 1);

	//Дальше перестраиваем полученую пирамиду
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = value[0];
		value[0] = value[i];
		value[i] = temp;
		siftDown(value, 0, i - 1);
	}
}