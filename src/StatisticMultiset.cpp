#include "StatisticMultiset.h"

template<class T>
StatisticMultiset<T>::StatisticMultiset(const T num) {
	AddNum(num);
};
template<class T>
StatisticMultiset<T>::StatisticMultiset(const std::multiset<T> &numbers) {
	AddNums(numbers);
};
template<class T>
StatisticMultiset<T>::StatisticMultiset(const std::vector<T> &numbers) {
	AddNums(numbers);
};
template<class T>
StatisticMultiset<T>::StatisticMultiset(const std::list<T> &numbers) {
	AddNums(numbers);
};
template<class T>
StatisticMultiset<T>::StatisticMultiset(const StatisticMultiset& a_stat_set) {
	AddNums(a_stat_set);
};
template<class T>
StatisticMultiset<T>::StatisticMultiset(const char* filename) {
	AddNums(filename);
};

template<class T>
T StatisticMultiset<T>::GetMax() const {
	return max;
}
template<class T>
T StatisticMultiset<T>::GetMin() const {
	return min;
}
template<class T>
float StatisticMultiset<T>::GetAvg() const {
	if (avgIsChanged) {
		float sum = 0;
		for (auto &val : data) { sum += val; }
		recentAvg = sum / data.size();
		avgIsChanged = 0;
	}
	return recentAvg;
}
template<class T>
int StatisticMultiset<T>::GetCountUnder(float threshold) const {
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
template<class T>
int StatisticMultiset<T>::GetCountAbove(float threshold) const {
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

template<class T>
void StatisticMultiset<T>::AddNum(const T num) {
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
template<class T>
void StatisticMultiset<T>::AddNums(const std::multiset<T> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
	avgIsChanged = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const std::vector<T> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
	avgIsChanged = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const std::list<T> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
	avgIsChanged = 1;
}
template<class T>
void StatisticMultiset<T>::AddNumsFromFile(const char* filename) {
	std::ifstream file(filename);
	int x;
	if (!file.fail()) {
		while (file >> x) { AddNum(x); }
		avgIsChanged = 1;
	}
}
template<class T>
void StatisticMultiset<T>::AddNums(const StatisticMultiset& a_stat_set) {
	AddNums(a_stat_set.data);
	avgIsChanged = 1;
}

template<class T>
void StatisticMultiset<T>::UpdateCache(const T &value) const {
	for (auto &it : aboveCache) {
		if (value > it.first) { it.second++; }
	}
	for (auto &it : underCache) {
		if (value < it.first) { it.second++; }
	}
}

template<class T>
StatisticMultiset::~StatisticMultiset() {
	data.clear();
	aboveCache.clear();
	underCache.clear();
}