#pragma once
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

template<typename T>
class StatisticMultiset {
public:
	T GetMax() const {
		return max;
	}
	T GetMin() const {
		return min;
	}
	float GetAvg() const {
		if (avgIsChanged) {
			float sum = 0;
			for (auto &val : data) { sum += val; }
			recentAvg = sum / data.size();
			avgIsChanged = 0;
		}
		return recentAvg;
	}
	int GetCountUnder(float threshold) const {
		for (auto &it : underCache) {
			if (threshold == it.first) return it.second;
		}
		unsigned int c = 0;
		for (auto &val : data) {
			if (val < threshold) { c++; }
		}
		underCache.push_back(std::make_pair(threshold, c));
		return c;
	}
	int GetCountAbove(float threshold) const {
		for (auto &it : aboveCache) {
			if (threshold == it.first) return it.second;
		}
		unsigned int c = 0;
		for (auto &val : data) {
			if (val > threshold) { c++; }
		}
		aboveCache.push_back(std::make_pair(threshold, c));
		return c;
	}
	void AddNum(T num) {
		if (data.empty()) {
			min = num;
			max = num;
		}
		else {
			if (num > max) { max = num; }
			else if (num < min) { min = num; }
		}
		data.insert(num);
		avgIsChanged = 1;
	}
	void AddNum(const std::multiset<T> &numbers) {
		for (auto &val : numbers) {
			AddNum(val);
		}
		avgIsChanged = 1;
	}
	void AddNum(const std::vector<T> &numbers) {
		for (auto &val : numbers) {
			AddNum(val);
		}
		avgIsChanged = 1;
	}
	void AddNum(const std::list<T> &numbers) {
		for (auto &val : numbers) {
			AddNum(val);
		}
		avgIsChanged = 1;
	}
	void AddNumsFromFile(const char* filename) {
		std::ifstream file(filename);
		int x;
		while (file >> x) { AddNum(x); }
		avgIsChanged = 1;
	}
	void AddNums(const StatisticMultiset& a_stat_set) {
		AddNum(a_stat_set.data);
		avgIsChanged = 1;
	}
private:
	std::multiset<T> data;
	T max, min;
	mutable float recentAvg;
	mutable bool avgIsChanged;
	mutable std::vector< std::pair<float, unsigned int> > aboveCache, underCache;
	void UpdateCache(const T &value) const {
		for (auto &it : aboveCache) {
			if (value > it.first) { it.second++; }
		}
		for (auto &it : underCache) {
			if (value < it.first) { it.second++; }
		}
	}
};