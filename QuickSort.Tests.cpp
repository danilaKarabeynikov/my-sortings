#pragma once
#include "pch.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include "../MySortings/QuickSort.h"

class QSortFixture
{
public:
	QSortFixture()
	{
		ascendingArray = new int[arrSize];
		descendingArray = new int[arrSize];
		lotsRepeatArray = new int[arrSize];
		for (int i = 0; i < arrSize; ++i)
		{
			descendingArray[i] = arrSize - i;
			ascendingArray[i] = i;
			lotsRepeatArray[i] = rand() % 10;
		}
	}
	void set(size_t size)
	{
		randomArray = new int[size];
		for (int i = 0; i < size; ++i)
			randomArray[i] = rand();
	}
	~QSortFixture()
	{
		delete[] randomArray;
		delete[] ascendingArray;
		delete[] descendingArray;
		delete[] lotsRepeatArray;
	}

	int* randomArray = nullptr;
	int* ascendingArray;
	int* descendingArray;
	int* lotsRepeatArray;
};

class TestQuickSort : public ::testing::Test
{
protected:
	void SetUp()
	{
		fixtData = new QSortFixture();
	}
	void TearDown()
	{
		delete fixtData;
	}
	QSortFixture* fixtData;
};

TEST_F(TestQuickSort, QuickSortCorrectWork)
{
	QuickSort<int>(fixtData->ascendingArray, arrSize);
	QuickSort<int>(fixtData->descendingArray, arrSize);
	QuickSort<int>(fixtData->lotsRepeatArray, arrSize);
	fixtData->set(arrSize);
	QuickSort<int>(fixtData->randomArray, arrSize);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

//TEST_F(TestQuickSort, CorrectFlagSortWork)
//{
//	QuickFlagSort<int*>(fixtData->ascendingArray, fixtData->ascendingArray + arrSize - 1);
//	QuickFlagSort<int*>(fixtData->descendingArray, fixtData->descendingArray + arrSize - 1);
//	QuickFlagSort<int*>(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize - 1);
//	fixtData->set(arrSize);
//	QuickFlagSort<int*>(fixtData->randomArray, fixtData->randomArray + arrSize - 1);
//
//	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
//}

TEST_F(TestQuickSort, TimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	QuickSort<int>(fixtData->ascendingArray, arrSize);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	QuickSort<int>(fixtData->descendingArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	QuickSort<int>(fixtData->lotsRepeatArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	QuickSort<int>(fixtData->randomArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
}
//
//TEST_F(TestQuickSort, QSortTimeAnalyze)
//{
//	auto start = std::chrono::high_resolution_clock::now();
//	QSort<int*>(fixtData->ascendingArray, fixtData->ascendingArray + arrSize - 1);
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "QUICK_SORT sort DIRECT order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	QSort<int*>(fixtData->descendingArray, fixtData->descendingArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "QUICK_SORT sort REVERSE order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	fixtData->set(arrSize);
//	start = std::chrono::high_resolution_clock::now();
//	QSort<int*>(fixtData->randomArray, fixtData->randomArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "QUICK_SORT sort RANDOM order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	QSort<int*>(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "QUICK_SORT sort LOTS REPEAT arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//}
//
//TEST_F(TestQuickSort, TimeFlagAnalyze)
//{
//	auto start = std::chrono::high_resolution_clock::now();
//	QuickFlagSort<int*>(fixtData->ascendingArray, fixtData->ascendingArray + arrSize - 1);
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "FLAG_QUICK_SORT sort DIRECT order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	QuickFlagSort<int*>(fixtData->descendingArray, fixtData->descendingArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "FLAG_QUICK_SORT sort REVERSE order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	fixtData->set(arrSize);
//	start = std::chrono::high_resolution_clock::now();
//	QuickFlagSort<int*>(fixtData->randomArray, fixtData->randomArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "FLAG_QUICK_SORT sort RANDOM order arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	QuickFlagSort<int*>(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize - 1);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//	std::cout << "FLAG_QUICK_SORT sort LOTS REPEAT arr time (microseconds): ";
//	std::cout << duration.count() << std::endl;
//}
int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

TEST_F(TestQuickSort, CompareWithStd)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(fixtData->ascendingArray, fixtData->ascendingArray + arrSize);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::sort(fixtData->descendingArray, fixtData->descendingArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	std::sort(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::sort(fixtData->randomArray, fixtData->randomArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;
}

TEST_F(TestQuickSort, CompareWithQSort)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::qsort(fixtData->ascendingArray, arrSize, sizeof(int), compare);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::qsort(fixtData->descendingArray, arrSize, sizeof(int), compare);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	std::qsort(fixtData->lotsRepeatArray, arrSize, sizeof(int), compare);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::qsort(fixtData->randomArray, arrSize, sizeof(int), compare);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;
}