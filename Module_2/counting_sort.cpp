#include <iostream>

void printMas(int* mas, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << mas[i] << ' ';
	}
	std::cout << std::endl;
}

void countingSort(int *mas, int size) {
	int max = mas[0];
	for(int i = 1; i < size; ++i) {
		if(max < mas[i]) {
			max = mas[i];
		}
	}
	++max;
	int* count_mas = new int[max];
	for(int i = 0; i < max; ++i) {
		count_mas[i] = 0;
	}
	for(int i = 0; i < size; ++i) {
		++count_mas[mas[i]];
	}
	int summ = 0;
	for(int i = 0; i < max; ++i) {
		summ += count_mas[i];
		count_mas[i] = summ;
	}	
	for(int i = 1; i < max; ++i) {
		for(int j = count_mas[i - 1]; j < count_mas[i]; ++j) {
			mas[j] = i;
		}
	}
	delete[] count_mas;
}

int main() {
	int mas[] = {4, 9, 8, 1, 4, 1, 4};
	int n = 7;
	printMas(mas, n);
	
	countingSort(mas, n);
	
	printMas(mas, n);
	return 0;
}
