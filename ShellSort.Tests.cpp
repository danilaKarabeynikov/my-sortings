#pragma once
#include "pch.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include "../MySortings/ShellSort.h"

class ShellFixture
{
public:
	ShellFixture()
	{
		ascendingArray = new int[arrSize];
		descendingArray = new int[arrSize];
		lotsRepeatArray = new int[arrSize];
		randomArray = new int[arrSize];
		int r = rand();
		for (int i = 0; i < arrSize; ++i)
		{
			descendingArray[i] = arrSize - i;
			ascendingArray[i] = i;
			lotsRepeatArray[i] = r % 10;
			randomArray[i] = r;
		}
	}
	/*void set(size_t size)
	{
		randomArray = new int[size];
		for (int i = 0; i < size; ++i)
			randomArray[i] = rand();
	}*/
	~ShellFixture()
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

class TestShell : public ::testing::Test
{
protected:
	void SetUp()
	{
		fixtData = new ShellFixture();
	}
	void TearDown()
	{
		delete fixtData;
	}
	ShellFixture* fixtData;
};

TEST_F(TestShell, CorrectSortingByFirstKnut)
{
	ShellSort<int>(fixtData->ascendingArray, arrSize, 1);
	ShellSort<int>(fixtData->descendingArray, arrSize, 1);
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 1);
	//fixtData->set(arrSize);
	ShellSort<int>(fixtData->randomArray, arrSize, 1);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

TEST_F(TestShell, CorrectSortingBySecondKnut)
{	
	//fixtData->set(arrSize);
	ShellSort<int>(fixtData->ascendingArray, arrSize, 2);
	ShellSort<int>(fixtData->descendingArray, arrSize, 2);
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 2);
	ShellSort<int>(fixtData->randomArray, arrSize, 2);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

TEST_F(TestShell, CorrectSortingBySedgwick)
{
	ShellSort<int>(fixtData->ascendingArray, arrSize, 3);
	ShellSort<int>(fixtData->descendingArray, arrSize, 3);
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 3);
	//fixtData->set(arrSize);
	ShellSort<int>(fixtData->randomArray, arrSize, 3);

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
}

TEST_F(TestShell, FirstKnutTimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->ascendingArray, arrSize, 1);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->descendingArray, arrSize, 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	//fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->randomArray, arrSize, 1);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
}

TEST_F(TestShell, SecondKnutTimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->ascendingArray, arrSize, 2);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->descendingArray, arrSize, 2);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 2);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	//fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->randomArray, arrSize, 2);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
}

TEST_F(TestShell, SedgewickTimeAnalyze)
{
	auto start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->ascendingArray, arrSize, 3);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nAscending array:   " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->descendingArray, arrSize, 3);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Descending array:  " << duration.count() << " (microseconds) " << std::endl;

	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->lotsRepeatArray, arrSize, 3);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Lots repeat array: " << duration.count() << " (microseconds) " << std::endl;

	//fixtData->set(arrSize);
	start = std::chrono::high_resolution_clock::now();
	ShellSort<int>(fixtData->randomArray, arrSize, 3);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Random array:      " << duration.count() << " (microseconds) \n" << std::endl;

	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
}
