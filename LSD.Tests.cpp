#pragma once
#include "pch.h"
#include "../MySortings/LSD.h"
#include <vector>
#include <list>

//TEST(LSD, EqualLength)
//{
//	std::list<std::string> strList{ "bac", "acb", "bbc" };
//	RadixLSD(strList.begin(), strList.end());
//
//	std::list<std::string> secondStrList{ "gdaa", "sbdh", "aaan", "dkll", "baac", "bbaac" };
//	RadixLSD(secondStrList.begin(), secondStrList.end());
//
//	ASSERT_TRUE(std::is_sorted(strList.begin(), strList.end()));
//	ASSERT_TRUE(std::is_sorted(strList.begin(), strList.end()));
//}
//
//TEST(LSD, DifferentLength)
//{
//	std::list<std::string> strList{ "gdaa", "sbdhhaa", "aaan", "dkll", "baac", "bbaac" };
//	RadixLSD(strList.begin(), strList.end());
//
//	std::vector<std::string> strVector{ "gdaa", "sbdhhaa", "aaan", "dkll", "baac", "bbaac" };
//	RadixLSD(strVector.begin(), strVector.end());
//
//	ASSERT_TRUE(std::is_sorted(strList.begin(), strList.end()));
//	ASSERT_TRUE(std::is_sorted(strVector.begin(), strVector.end()));
//}