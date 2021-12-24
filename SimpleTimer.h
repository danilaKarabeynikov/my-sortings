#pragma once
#include <iostream>
#include <chrono>

class SimpleTimer
{
public:
	SimpleTimer() : start(std::chrono::high_resolution_clock::now()) {};
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "Duration: " << duration.count() * 1000 << " ms" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};