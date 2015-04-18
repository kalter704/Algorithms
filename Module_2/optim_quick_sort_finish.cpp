#include "stdio.h"
#include <cstdlib>
#include <algorithm>

typedef unsigned int my_type;

const size_t RANGE = 257;

const long long START_SIZE = 1000000;


bool less(const my_type &lhs, const my_type	&rhs) {
	return lhs <= rhs;
}

template <typename data_t> 
void swap(data_t &lhs, data_t &rhs) {
	data_t temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename data_t, typename less_t>
void ins_sort(data_t *begin, data_t *end, less_t &less) {
  for(data_t *i = begin + 1; i < end; ++i) {
    data_t temp = *i;
    data_t *j = i;
    for( ; (j != begin) && less(temp, *(j - 1)); --j) {
      *(j) = *(j - 1);
    }
    *(j) = temp;
  }
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
	if(n < 25) {                          
		ins_sort(&mas[0], &mas[n], less);
		return;	
	}
	swap(mas[rand() % n], mas[n - 1]);
	size_t pivot = split(mas, n, less);
	quick_sort(&mas[0], pivot, less);
	quick_sort(&mas[pivot + 1], n - pivot - 1, less);
}

void growMas(my_type** mas, long long &size) {
	long long new_size = size * 2;
	my_type *new_mas = new my_type[new_size];
	for(long long i = 0; i < size; ++i) {
		new_mas[i] = (*mas)[i];
	}
	delete[] (*mas);
	(*mas) = new_mas;
	size = new_size;
} 

int main() {
	srand(77);
	unsigned int n;
	my_type *mas = new my_type[START_SIZE];
	long long size = START_SIZE;
	long long real_size = 0;
	long long i = 0;
	while(fscanf(stdin, "%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", 
					&mas[i], &mas[i + 1], &mas[i + 2], &mas[i + 3], &mas[i + 4], 
					&mas[i + 5], &mas[i + 6], &mas[i + 7], &mas[i + 8], &mas[i + 9]) == 10) 
	{
		i += 10;
		if(i >= size) {
			growMas(&mas, size);
		}
	}
	real_size = i;
	quick_sort(mas, real_size, less);
	
	for(i = 9; i < real_size; i += 10) {
		printf("%d ", mas[i]);
	}
	delete[] mas;
	
	return 0;
}
