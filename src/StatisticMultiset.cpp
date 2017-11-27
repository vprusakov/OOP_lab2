#include "StatisticMultiset.h"

template class StatisticMultiset<int>;
template class StatisticMultiset<float>;
template class StatisticMultiset<double>;

template <typename T>
T StatisticMultiset<T>::GetMax() const {
	if (!data.size()) throw "Nothing is in StatisticMultiset.\n";
	return *data.rbegin();
}
template <typename T>
T StatisticMultiset<T>::GetMin() const {
	if (!data.size()) throw "Nothing is in StatisticMultiset.\n";
	return *data.begin();
}
template <typename T>
float StatisticMultiset<T>::GetAvg() const {
	if (!data.size()) throw "Nothing is in StatisticMultiset.\n";
	if (avg_changed) {
		float sum = 0;
		for (auto &val : data) { sum += val; }
		avg_cache = sum / data.size();
	}
	return avg_cache;
}
template <typename T>
unsigned int StatisticMultiset<T>::GetCountAbove(const float &threshold) const {
	if (!data.size()) throw "Nothing is in StatisticMultiset.\n";
	if (above_threshold_changed) {
		for (auto &th : above_cache) {
			th.second = 0;
			for (auto &val : data) {
				if (val > th.first) { ++th.second; }
			}
		}
	}
	
	for (auto &it : above_cache) {
		if (threshold == it.first) return it.second;
	}

	std::pair<float, unsigned int> p(threshold, 0);

	for (auto &val : data) {
		if (val > threshold) {
			++p.second;
		};
	}
	if (above_cache.size() == cache_size) {
		above_cache.pop_back();
	}
	above_cache.push_front(p);
	return p.second;
}
template <typename T>
unsigned int StatisticMultiset<T>::GetCountUnder(const float &threshold) const {
	if (!data.size()) throw "Nothing is in StatisticMultiset.\n";
	if (under_threshold_changed) {
		for (auto &th : under_cache) {
			th.second = 0;
			for (auto &val : data) {
				if (val < th.first) { ++th.second; }
			}
		}
	}
	for (auto &it : under_cache) {
		if (threshold == it.first) return it.second;
	}

	std::pair<float, unsigned int> p(threshold, 0);

	for (auto &val : data) {
		if (val < threshold) {
			++p.second;
		};
	}
	if (under_cache.size() == cache_size) {
		under_cache.pop_back();
	}
	under_cache.push_front(p);
	return p.second;
}


template <typename T>
void StatisticMultiset<T>::AddNum(const T &num) {
	data.insert(num);
	avg_changed = 1;
	above_threshold_changed = 1;
	under_threshold_changed = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const std::multiset<T> &numbers) {
	for (auto &val : numbers) {
		data.insert(val);
	}
	avg_changed = 1;
	above_threshold_changed = 1;
	under_threshold_changed = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const std::vector<T> &numbers) {
	for (auto &val : numbers) {
		data.insert(val);
	}
	avg_changed = 1;
	above_threshold_changed = 1;
	under_threshold_changed = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const std::list<T> &numbers) {
	for (auto &val : numbers) {
		data.insert(val);
	}
	avg_changed = 1;
	above_threshold_changed = 1;
	under_threshold_changed = 1;
}
template<class T>
void StatisticMultiset<T>::AddNums(const StatisticMultiset& a_stat_set) {
	for (auto &val : a_stat_set.data) {
		this->data.insert(val);
	}
	avg_changed = 1;
	above_threshold_changed = 1;
	under_threshold_changed = 1;
}
template<class T>
void StatisticMultiset<T>::AddNumsFromFile(const std::string &filename) {
	std::ifstream file(filename);
	int x;
	if (!file.fail()) {
		while (file >> x) {
			data.insert(x);
		}
		avg_changed = 1;
		above_threshold_changed = 1;
		under_threshold_changed = 1;
	}
	else throw "Can't open the file.\n";
}