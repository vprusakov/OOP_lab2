#pragma once
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

class StatisticMultiset {
public:
	// Добавляет число в набор.
	void AddNum(int num);
	// Максимальное число в наборе.
	int GetMax() const;
	// Минимальное число в наборе.
	int GetMin() const;
	// Среднее арифметическое всего набора.
	float GetAvg() const;
	// Кол-во чисел в наборе меньше заданного порога.
	int GetCountUnder(float threshold) const;
	// Кол-во чисел в наборе больше заданного порога.
	int GetCountAbove(float threshold) const;
	// Чтение
	void AddNum(const std::multiset<int>& numbers);
	void AddNum(const std::vector<int>& numbers);
	void AddNum(const std::list<int>& numbers);
	void AddNumsFromFile(const char* filename);
	void AddNums(const StatisticMultiset& a_stat_set);
	// Вывод всех значений
	void Print();
private:
	std::multiset<int> data;
	int max;
	int min;
};