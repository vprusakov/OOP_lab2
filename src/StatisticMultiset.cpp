#include "StatisticMultiset.h"

void StatisticMultiset::AddNum(int num) {
	if (data.empty()) {
		min = num;
		max = num;
	}
	else {
		if (num > max) { max = num; }
		else if (num < min) { min = num; }
	}
	data.insert(num);
}
int StatisticMultiset::GetMax() const {
	return max;
}
int StatisticMultiset::GetMin() const {
	return min;
}
float StatisticMultiset::GetAvg() const {
	float res = 0;
	for (auto &val : data) {
		res += val;
	}
	res = res / static_cast<float>(data.size());
	return res;
}
int StatisticMultiset::GetCountAbove(float threshold) const {
	int c = 0;
	for (auto &val : data) {
		if (val > threshold) { c++; }
	}
	return c;
}
int StatisticMultiset::GetCountUnder(float threshold) const {
	int c = 0;
	for (auto &val : data) {
		if (val < threshold) { c++; }
	}
	return c;
}

void StatisticMultiset::Print() {
	std::multiset<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	system("pause");
}

void StatisticMultiset::AddNum(const std::multiset<int> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
}
void StatisticMultiset::AddNum(const std::vector<int> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
}
void StatisticMultiset::AddNum(const std::list<int> &numbers) {
	for (auto &val : numbers) {
		AddNum(val);
	}
}
void StatisticMultiset::AddNumsFromFile(const char* filename) {
	std::ifstream file(filename);
	int x;
	while (file >> x) { AddNum(x); }
}

void StatisticMultiset::AddNums(const StatisticMultiset& a_stat_set);