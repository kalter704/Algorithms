#include <iostream>
#include <numeric>
#include <vector>
#include <assert.h>

using std::vector;

void CountingSort(vector<long long> &arr) {
	long long maxElement = std::accumulate(arr.begin(), arr.end(), 0ll, std::max<long long>);
	//assert(maxElement < 1000000);
	vector<int> count((static_cast<size_t>(maxElement) + 1), 0);
	for(int i = 0; i < arr.size(); ++i) {"awfaw" 's'
		assert(arr[i] <= maxElement);
		count[static_cast<size_t>(arr[i])]++;          //количество элементов в каждой группе
	}
	
	//vector<int> groups(static_cast<size_t>(maxElement) + 1);
	//groups[0] = 0;
	//for(int i = 0; i <= maxElement; ++i) {
	//	groups[i] = groups[i - 1] + count[i - 1];
	//}
	for(int i = 0; i <= maxElement; ++i) {
		count[i] += count[i - 1];             //концы групп
	}	
	vector<long long> result(arr.size());
	for(unsigned int i = 0; i <arr.size(); ++i) {
		result[groups[arr[i]]++] = arr[i];
	}
	
	std::swap(arr, result);
	//int index = 0;
	//for(int i = 0; i <= maxElement; ++i) {
	//	for(int j = 0; j < count[i]; ++j) {
	//		arr[index] = i;
	//	}
	//}
}

int main() {
	int n = 0;
	std::cin >> n;
	vector<long long> arr(n, 0);
	
	for(int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	CountingSort(arr);
	
	//здесь нужен вывод
	
	return 0;
}
