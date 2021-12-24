#pragma once
#include "pch.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include "../MySortings/MergeSort.h"

float units = 1000000;

class MergeFixture
{
public:
	MergeFixture()
	{
		ascendingArray = new int[arrSize];
		descendingArray = new int[arrSize];
		lotsRepeatArray = new int[arrSize];
		for (int i = 0; i < arrSize; ++i)
		{
			descendingArray[i] = arrSize - i;
			ascendingArray[i] = i;
			lotsRepeatArray[i] = i % 2;
		}
	}
	void set(size_t size)
	{
		randomArray = new int[size];
		for (int i = 0; i < size; ++i)
			randomArray[i] = rand();
	}
	~MergeFixture()
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

class TestMergeSort : public ::testing::Test
{
protected:
	void SetUp()
	{
		fixtData = new MergeFixture();
	}
	void TearDown()
	{
		delete fixtData;
	}
	MergeFixture* fixtData;
};
#define Sort MergeSort
TEST_F(TestMergeSort, MergeSortCorrectWork)
{
	Sort<int>(fixtData->ascendingArray, 0, arrSize - 1);
	Sort<int>(fixtData->descendingArray, 0, arrSize - 1);
	Sort<int>(fixtData->lotsRepeatArray, 0, arrSize - 1);
	fixtData->set(arrSize);
	Sort<int>(fixtData->randomArray, 0, arrSize - 1);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

TEST_F(TestMergeSort, TimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	MergeSort<int>(fixtData->ascendingArray, 0, arrSize - 1);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	std::cout << "\nAscending array:   " << duration.count() / units << " (milliseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	MergeSort<int>(fixtData->descendingArray, 0, arrSize - 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nDescending array:  " << duration.count() / units << " (milliseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	MergeSort<int>(fixtData->randomArray, 0, arrSize - 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nRandom array:      " << duration.count() / units << " (milliseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	MergeSort<int>(fixtData->lotsRepeatArray, 0, arrSize - 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nLots repeat array: " << duration.count() / units << " (milliseconds) \n" << std::endl;
}

TEST_F(TestMergeSort, CompareWithSTL)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::stable_sort(fixtData->ascendingArray, fixtData->ascendingArray + arrSize);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::stable_sort(fixtData->descendingArray, fixtData->descendingArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	std::stable_sort(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::stable_sort(fixtData->randomArray, fixtData->randomArray + arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;
}

TEST_F(TestMergeSort, UpMergeSortCorrectWork)
{
	UpMergeSort<int>(fixtData->ascendingArray, arrSize);
	UpMergeSort<int>(fixtData->descendingArray, arrSize);
	UpMergeSort<int>(fixtData->lotsRepeatArray, arrSize);
	fixtData->set(arrSize);
	UpMergeSort<int>(fixtData->randomArray, arrSize);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

TEST_F(TestMergeSort, UpTimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	UpMergeSort<int>(fixtData->ascendingArray, arrSize);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	std::cout << "\nAscending array:   " << duration.count() / units << " (milliseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	UpMergeSort<int>(fixtData->descendingArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nDescending array:  " << duration.count() / units << " (milliseconds) " << std::endl;

	fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	UpMergeSort<int>(fixtData->randomArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nRandom array:      " << duration.count() / units << " (milliseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	UpMergeSort<int>(fixtData->lotsRepeatArray, arrSize);
	stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	std::cout << "\nLots repeat array: " << duration.count() / units << " (milliseconds) \n" << std::endl;
}