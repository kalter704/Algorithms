#include <cstdio>
#include <iostream>

//template <typename data_t>
bool less(const int &lhs, const int &rhs) {
	return lhs < rhs;
}

template <typename data_t, typename less_t>
void merge(
				 data_t *a, size_t size_a, 
				 data_t *b, size_t size_b, 
				 data_t *c, 
				 less_t &less) 
{
	int i = size_a - 1,
			j = size_b - 1;
	for( ; i >= 0 && j >= 0; ) {
		if(less(a[i], b[j])) {
			c[i + j + 1] = b[j];
			j--;
		} else {
			c[i + j + 1] = a[i];
			i--;
		}
	}
	if(i < 0) {
		i++;
		for( ; j >= 0; --j) {
			c[i + j] = b[j];
		}
	} else {
		j++;
		for( ; i >= 0; --i) {
			c[i + j] = a[i];
		}
	}
}

int main() {
	/*
	int a[] = {0, 4, 7};
	int b[] = {2, 3, 9};
	int *c = new int[6];
	*/
	//merge(a, 3, b, 3, c, less);
	/*
	for(int i = 0; i < 6; ++i) {
		std::cout << c[i] << ' ';
	}
	*/
	return 0;
}
