//#include <cstdio>
#include "stdio.h"
#include <cstdlib>
#include <algorithm>

typedef unsigned int my_type;

const size_t RANGE = 257;

const long long START_SIZE = 1000000;
//////////////////////////////////////
int digitByte(my_type num, int radix) {
	long long byte_radix = 255;
	for(size_t i = 0; i < radix; ++i) {
		byte_radix = byte_radix << 8;
	}
	byte_radix = num & byte_radix;
	for(size_t i = 0; i < radix; ++i) {
		byte_radix = byte_radix >> 8;
	}
	return byte_radix;
}

void lsdCounting(my_type* mas, size_t n, int radix) {
	my_type count[RANGE] = {0};
	my_type t_mas[n];
	size_t i;
	for(i = 0; i < n; ++i) {
		++count[digitByte(mas[i], radix) + 1];
	}
	for(i = 1; i < RANGE; ++i) {
		count[i] += count[i - 1];
	}
	for(i = 0; i < n; ++i) {
		t_mas[count[digitByte(mas[i], radix)]++] = mas[i];
	}
	for(i = 0; i < n; ++i) {
		mas[i] = t_mas[i];
	}
}

void lsdSort(my_type* mas, size_t n) {
	for(size_t radix = 0; radix < 4; ++radix) {
		lsdCounting(mas, n, radix);
	}
}

/////////////////////////////////////


bool less(const my_type &lhs, const my_type	&rhs) {
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

//template <typename data_t, typename less_t>
//size_t split(data_t *mas, size_t n, less_t &less) {
//	size_t i = 0,
//				 j = n - 1;
//	int direction = 0;
////					for(int i = 0; i < n; ++i) {
////						printf("%d ", mas[i]);
////					}
////					printf("\n");
//	while(i != j) {
//		if(less(mas[j], mas[i]) xor direction) {
//			swap(mas[i], mas[j]);
//			direction = !direction;
//			swap(i, j);
//		}
//		if(direction) {
//			++j;
//		} else {
//			--j;
//		}
//	}
////				for(int i = 0; i < n; ++i) {
////					printf("%d ", mas[i]);
////				}
////				printf("\n");
//	return i;
//}

template <typename data_t, typename less_t>
void quick_sort(data_t *mas, size_t n, less_t &less) {
	if(n < 100) {
		//std::sort(&mas[0], &mas[n], less);
		lsdSort(mas, n);
		return;
	}
	swap(mas[rand() % n], mas[n - 1]);
	size_t pivot = split(mas, n, less);
//				for(int i = 0; i < n; ++i) {
//					printf("%d ", mas[i]);
//				}
//				printf("\n");
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
	//scanf("%d", &n);
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
//	for(int i = 0; i < real_size; ++i) {
//		printf("%d ", mas[i]);
//	}
	//printf("%d", mas[k]);
	delete[] mas;
	
	return 0;
}
