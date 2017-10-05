#include "StatisticMultiset.h"

using namespace std;

int main() {
	StatisticMultiset a;
	/*
	a.AddNum(4);
	a.AddNum(1);
	a.AddNum(3);
	a.AddNum(2);
	std::cout << a.GetMax() << " " << a.GetMin() << std::endl;
	std::cout << a.GetAvg() << std::endl;
	cout << a.GetCountAbove(1.5) << endl;
	cout << a.GetCountUnder(3.5) << endl;
	*/
	vector<int> v = { 5, 6, 0, -1 };
	a.AddNum(v);
	//a.AddNumsFromFile("../input_files/file.txt");
	a.Print();

	return 0;
}