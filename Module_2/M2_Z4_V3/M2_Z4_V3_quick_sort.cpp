#include <cstdio>
#include <cstdlib>

bool less(const int &lhs, const int	&rhs) {
	return lhs <= rhs;
}

template <typename data_t> 
void swap(data_t &lhs, data_t &rhs) {
	data_t temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename data_t>
size_t distance(data_t *begin, data_t *end) {
	size_t dist = 0;
	for( ; begin != end; ++begin, ++dist) {}
	return dist;
}

template <typename data_t, typename less_t>
size_t split(data_t *mas, size_t n, less_t &less) {
	size_t i = 0,
				 j = 0;
	while(j < n - 1) {
		if(less(mas[j], mas[n - 1])) {
			swap(mas[i], mas[j]);
			i++;
			j++;
		} else {
			j++;
		}
	}
	swap(mas[i], mas[n - 1]);
	return i;
}

template <typename data_t, typename less_t>
void quick_sort(data_t *mas, size_t n, less_t &less) {
	if(n < 2) {
		return;
	}
	int index = rand() % n;
	swap(mas[index], mas[n - 1]);
	size_t pivot = split(mas, n, less);
	quick_sort(&mas[0], pivot, less);
	quick_sort(&mas[pivot + 1], n - pivot - 1, less);
}

int main() {
	srand(77);
	int n, k;
	scanf("%d %d", &n, &k);
	int *mas = new int[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &mas[i]);
	}
	quick_sort(mas, n, less);
	printf("%d", mas[k]);
	delete[] mas;
	return 0;
}
