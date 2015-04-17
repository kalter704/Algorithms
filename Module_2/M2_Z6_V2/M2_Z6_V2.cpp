// 6_2. LSD для long long.
// Дан массив неотрицательных целых 64-разрядных чисел. Количество чисел не больше 106. 
// Отсортировать массив методом поразрядной сортировки LSD по байтам.

// метод digitByte из числа num добывает байт заданный в radix. 
// А остальное как в стондартной сортировке llsd_sort

#include <cstdio>

const size_t RANGE = 257;

template <typename data_t>
void printVector(data_t *vector, size_t size) {
	for(size_t i = 0; i < size; ++i) {
		printf("%lld\n", vector[i]);
	}
	printf("\n\n");
}

int digitByte(long long num, int radix) {
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

void lsdCounting(long long* mas, size_t n, int radix) {
	long long count[RANGE] = {0};
	long long t_mas[n];
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

void lsdSort(long long* mas, size_t n) {
	for(size_t radix = 0; radix < 8; ++radix) {
		lsdCounting(mas, n, radix);
	}
}

int main() {
	size_t size = 0;
	scanf("%d", &size);
	long long* mas = new long long[size];
	for(size_t i = 0; i < size; ++i) {
		scanf("%lld", &mas[i]);
	}
	lsdSort(mas, size);
	for(size_t i = 0; i < size; ++i) {
		printf("%lld\n", mas[i]);
	}
	return 0;
}
