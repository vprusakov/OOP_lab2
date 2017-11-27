#include "StatisticMultiset.h"

int main() {
	try {
		std::cout << "Lab 02" << std::endl;
		StatisticMultiset<int> ms1;
		ms1.AddNum(89);
		ms1.AddNum(54);
		ms1.AddNum(54);
		ms1.AddNum(24);
		StatisticMultiset<int> ms2;
		std::vector<int> somedata = { 10, 40, 6, 87 };
		ms2.AddNums(somedata);
		StatisticMultiset<int> ms3;
		ms3.AddNums(ms1);
		ms3.AddNums(ms2);
		std::cout << "Min: " << ms3.GetMin()
			<< " Avg: " << ms3.GetAvg()
			<< " Max: " << ms3.GetMax()
			<< std::endl;
	}
	catch (const char *e) {
		std::cerr << e << std::endl;
	}
	return 0;
}