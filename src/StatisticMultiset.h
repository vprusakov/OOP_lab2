#pragma once
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <deque>
#include <string>

template <typename T>
class StatisticMultiset {
public:
    StatisticMultiset() = default;
    ~StatisticMultiset() = default;
	
	T GetMax() const;
	T GetMin() const;
	float GetAvg() const;
	unsigned int GetCountAbove(const float &) const;
	unsigned int GetCountUnder(const float &) const;


	void AddNum(const T &num);
	void AddNums(const std::multiset<T>&);
	void AddNums(const std::vector<T>&);
	void AddNums(const std::list<T>&);
	void AddNums(const StatisticMultiset&);
	void AddNumsFromFile(const std::string &filename);

private:
	std::multiset<T> data;
	mutable bool avg_changed;
	mutable float avg_cache;

	mutable short cache_size = 3;
	mutable std::deque< std::pair<float, unsigned int> > above_cache, under_cache;
	mutable bool above_threshold_changed, under_threshold_changed;
};