#include <cstdio>

const size_t RANGE = 3;

void printVector(int* mas, int n) {
	for(int i = 0; i < n; ++i) {
		printf("%d ", mas[i]);
	}
	printf("\n");
}

int digit(int num, int radix) {
	int t_num = 1;
	for(int i = 0; i < radix; ++i) {
		t_num = t_num << 1;
	}
	num = num & t_num;
	if(num != 0) { 
		for(int i = 0; i < radix; ++i) {
			num = num >> 1;
		}
	}
	return num;
}

void countingSort(int* mas, size_t n, int radix) {
	size_t i;
	int count[RANGE] = {0};
	for(i = 0; i < n; ++i) {
		++count[digit(mas[i], radix) + 1];
	}
	for(i = 1; i < RANGE; ++i) {
		count[i] += count[i - 1];
	}
	int t_mas[n];
	for(i = 0; i < n; ++i) {
		t_mas[count[digit(mas[i], radix)]++] = mas[i];
	}
	for(i = 0; i < n; ++i) {
		mas[i] = t_mas[i];
	}
	//printVector(mas, n);
}

void msdRadixPass(int* mas, size_t n, int radix) {
	if(n < 2) {
		return;
	}
	if(radix < 0) {
		return;
	}
	countingSort(mas, n, radix);
	printVector(mas, n);
	bool flag = true;
	int start = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(digit(mas[i], radix) != digit(mas[i + 1], radix)) {
			msdRadixPass(&mas[start], (i - start + 1), radix - 1);
			start = i + 1;
			//printVector(mas, n);
			flag = false;
		}
	}
	if(flag) {
		msdRadixPass(mas, n, radix - 1);
	} else {
		msdRadixPass(&mas[start], (n - start), radix - 1);
	}
}

void msdRadixSort(int* mas, size_t n) {
		msdRadixPass(mas, n, 31);
}

int main() {
	/*
	int num = 3;
	printf("%d\n", digit(num, 2));
	*/
	/*
	int mas[] = {1, 2, 3, 4, 5};
	int n = 5;
	countingSort(mas, n, 0);
	printVector(mas, n);
	*/
	
	int mas[] = {1, -1, -6514654, 7, 4, -9, 3, 5, 15, -5, 4, 5461, 48, 0, 15};
	int n = 12;
	msdRadixSort(mas, n);
	printVector(mas, n);
  return 0;
}
