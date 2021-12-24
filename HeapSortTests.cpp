#pragma once
#include "pch.h"
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include "../MySortings/HeapSort.h"


//
//class HeapFixture
//{
//public:
//	HeapFixture()
//	{
//		ascendingArray = new int[arrSize];
//		descendingArray = new int[arrSize];
//		lotsRepeatArray = new int[arrSize];
//		for (int i = 0; i < arrSize; ++i)
//		{
//			descendingArray[i] = arrSize - i;
//			ascendingArray[i] = i;
//			lotsRepeatArray[i] = i % 2;
//		}
//	}
//	void set(size_t size)
//	{
//		randomArray = new int[size];
//		for (int i = 0; i < size; ++i)
//			randomArray[i] = rand();
//	}
//	~HeapFixture()
//	{
//		delete[] randomArray;
//		delete[] ascendingArray;
//		delete[] descendingArray;
//		delete[] lotsRepeatArray;
//	}
//
//	int* randomArray = nullptr;
//	int* ascendingArray;
//	int* descendingArray;
//	int* lotsRepeatArray;
//};
//
//class TestHeap : public ::testing::Test
//{
//protected:
//	void SetUp()
//	{
//		fixtData = new HeapFixture();
//	}
//	void TearDown()
//	{
//		delete fixtData;
//	}
//	HeapFixture* fixtData;
//};
//


//TEST_F(TestHeap, CheckingCorrectSorting)
//{
//	heapSort<int*>(fixtData->ascendingArray, arrSize);
//	heapSort<int*>(fixtData->descendingArray, arrSize);
//	heapSort<int*>(fixtData->lotsRepeatArray, arrSize);
//	fixtData->set(arrSize);
//	heapSort<int*>(fixtData->randomArray, arrSize);
//
//	EXPECT_TRUE(std::is_sorted(fixtData->ascendingArray, fixtData->ascendingArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->descendingArray, fixtData->descendingArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize));
//	EXPECT_TRUE(std::is_sorted(fixtData->randomArray, fixtData->randomArray + arrSize));
//	
//}
//
//TEST_F(TestHeap, TimeAnalyze)
//{
//	auto start = std::chrono::high_resolution_clock::now();
//	heapSort<int*>(fixtData->ascendingArray, arrSize);
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = stop - start;
//	std::cout << "\nAscending array:   " << duration.count() / units << " (milliseconds) " << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	heapSort<int*>(fixtData->descendingArray, arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nDescending array:  " << duration.count() / units << " (milliseconds) " << std::endl;
//
//	fixtData->set(arrSize);
//	start = std::chrono::high_resolution_clock::now();
//	heapSort<int*>(fixtData->randomArray, arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nRandom array:      " << duration.count() / units << " (milliseconds) " << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	heapSort<int*>(fixtData->lotsRepeatArray,arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nLots repeat array: " << duration.count() / units << " (milliseconds) \n" << std::endl;
//}
//
//TEST_F(TestHeap, CompareWithStd)
//{
//	auto start = std::chrono::high_resolution_clock::now();
//	std::make_heap(fixtData->ascendingArray, fixtData->ascendingArray + arrSize);
//	std::sort_heap(fixtData->ascendingArray, fixtData->ascendingArray + arrSize);
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = stop - start;
//	std::cout << "\nAscending array:   " << duration.count() / units << " (milliseconds) " << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	std::make_heap(fixtData->descendingArray, fixtData->descendingArray + arrSize);
//	std::sort_heap(fixtData->descendingArray, fixtData->descendingArray + arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nDescending array:  " << duration.count() / units << " (milliseconds) " << std::endl;
//
//
//	fixtData->set(arrSize);
//	start = std::chrono::high_resolution_clock::now();
//	std::make_heap(fixtData->randomArray, fixtData->randomArray + arrSize);
//	std::sort_heap(fixtData->randomArray, fixtData->randomArray + arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nRandom array:      " << duration.count() / units << " (milliseconds) " << std::endl;
//
//	start = std::chrono::high_resolution_clock::now();
//	std::make_heap(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize);
//	std::sort_heap(fixtData->lotsRepeatArray, fixtData->lotsRepeatArray + arrSize);
//	stop = std::chrono::high_resolution_clock::now();
//	duration = stop - start;
//	std::cout << "\nLots repeat array: " << duration.count() / units << " (milliseconds) \n" << std::endl;
//}