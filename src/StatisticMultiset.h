#pragma once
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

template<class T>
class StatisticMultiset {
public:
    StatisticMultiset() = default;
    explicit StatisticMultiset(T num);
    explicit StatisticMultiset(const std::multiset<T>&);
    explicit StatisticMultiset(const std::vector<T>&);
    explicit StatisticMultiset(const std::list<T>&);
    explicit StatisticMultiset(const StatisticMultiset&);
    explicit StatisticMultiset(const char*);
    ~StatisticMultiset();

	T GetMax() const;
	T GetMin() const;
	float GetAvg() const;
	int GetCountUnder(float) const;
	int GetCountAbove(float) const;

	void AddNum(T num);
	void AddNums(const std::multiset<T>&);
	void AddNums(const std::vector<T>&);
	void AddNums(const std::list<T>&);
	void AddNumsFromFile(const char*);
	void AddNums(const StatisticMultiset&);
private:
	std::multiset<T> data;
	T max, min;
	mutable float recentAvg;
	mutable bool avgIsChanged;
	mutable std::vector< std::pair<float, unsigned int> > aboveCache, underCache;
	void UpdateCache(const T&) const;
};