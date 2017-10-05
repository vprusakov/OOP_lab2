#pragma once
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

class StatisticMultiset {
public:
	// ��������� ����� � �����.
	void AddNum(int num);
	// ������������ ����� � ������.
	int GetMax() const;
	// ����������� ����� � ������.
	int GetMin() const;
	// ������� �������������� ����� ������.
	float GetAvg() const;
	// ���-�� ����� � ������ ������ ��������� ������.
	int GetCountUnder(float threshold) const;
	// ���-�� ����� � ������ ������ ��������� ������.
	int GetCountAbove(float threshold) const;
	// ������
	void AddNum(const std::multiset<int>& numbers);
	void AddNum(const std::vector<int>& numbers);
	void AddNum(const std::list<int>& numbers);
	void AddNumsFromFile(const char* filename);
	void AddNums(const StatisticMultiset& a_stat_set);
	// ����� ���� ��������
	void Print();
private:
	std::multiset<int> data;
	int max;
	int min;
};