#pragma once
#include "stdafx.h"

template <typename Y>
void Merge(Y *arr, long first, long last)
{
	int middle, start, final, j;
	long *mas = new long[last+1];
	middle = (first + last) / 2;
	start = first; 
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (arr[start] < arr[final])))
		{
			mas[j] = arr[start];
			start++;
		}
		else
		{
			mas[j] = arr[final];
			final++;
		}
	
	for (j = first; j <= last; j++)
		arr[j] = mas[j];
	delete[]mas;
}

template <typename T>
void MergeSort(T *arr, long first, long last)
{
	if (first < last)
	{
		MergeSort(arr, first, (first + last) / 2);
		MergeSort(arr, (first + last) / 2 + 1, last);
		Merge(arr, first, last);
	}
}


template <typename N>
void UpMergeSort(N *arr, int size)
{
	int step = 1;  
	int *mas = new int[size];

	while (step < size)
	{
		int index = 0;  
		int l_border = 0;  
		int middle = l_border + step;
		int r_border = l_border + step * 2; 

		do
		{
			middle = middle < size ? middle : size;  // сортируемый участок не выходит за границы последовательности
			r_border = r_border < size ? r_border : size;
			int i1 = l_border, i2 = middle; // индексы сравниваемых элементов

			for (; i1 < middle && i2 < r_border; )
			{
				arr[i1] < arr[i2] ? mas[index++] = arr[i1++] : mas[index++] = arr[i2++];
			}
			
			while (i1 < middle)
				mas[index++] = arr[i1++];
			while (i2 < r_border)
				mas[index++] = arr[i2++];

			l_border += step * 2;
			middle += step * 2;
			r_border += step * 2;

		} while (l_border < size);

		for (int i = 0; i < size; i++)
			arr[i] = mas[i];
		step *= 2;
	}
	delete[]mas;
}