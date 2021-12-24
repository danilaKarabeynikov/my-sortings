#pragma once
#include <map>
#include <deque>

template<typename T>
void makeSortM(std::map<char, std::deque<T>>& sortM, std::deque<T>& work, int strLen)
{
	while (!work.empty())
	{
		auto itStr = work.front();
		sortM[(*itStr)[strLen]].push_back(itStr);
		work.pop_front();
	}
}

template<typename T>
void makeSortedWork(std::map<char, std::deque<T>>& sortM, std::deque<T>& work)
{
	auto itMap = sortM.begin();
	while (itMap != sortM.end())
	{
		auto itDeq = itMap->second;
		while (!itDeq.empty())
		{
			work.push_back(itDeq.front());
			itDeq.pop_front();
		}
		++itMap;
	}
}

template<typename T>
void copySortedWorkToResult(T begin, T end, std::deque<T>& work)
{
	std::deque<std::iterator_traits<T>::value_type> valueDeq;
	auto it = work.begin();
	while (it != work.end())
		valueDeq.push_back(*(*it++));

	auto valIt = valueDeq.begin();
	while (valIt != valueDeq.end())
		*begin++ = *valIt++;
}

template<typename T>
int strLength(T strIt)
{
	std::string str(*strIt);
	return str.length();
}

template<typename T>
void addStrToWorkDeque(std::deque<T>& work, std::deque<T>& eqLenStr)
{
	auto deqIt = eqLenStr.begin();
	while (deqIt != eqLenStr.end())
		work.push_back(*deqIt++);
}

template<typename T>
void RadixLSD(T begin, T end)
{
	std::map<int, std::deque<T>> diffLenStr;
	T strIt = begin;
	while (strIt != end)
		diffLenStr[strLength(strIt)].push_back(strIt++);

	int currentStrLength = diffLenStr.rbegin()->first;
	std::deque<T> work;
	addStrToWorkDeque(work, diffLenStr[currentStrLength]);
	std::map<char, std::deque<T>>sortM;

	while (--currentStrLength >= 0)
	{
		auto it = diffLenStr.find(currentStrLength);
		if (it != diffLenStr.end())
			addStrToWorkDeque(work, diffLenStr[currentStrLength]);

		makeSortM(sortM, work, currentStrLength);
		makeSortedWork(sortM, work);
		sortM.clear();
	}

	copySortedWorkToResult(begin, end, work);
}