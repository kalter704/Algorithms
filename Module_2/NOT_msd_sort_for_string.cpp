#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

const size_t RANGE = 257;

void printVector(std::string* mas, int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << mas[i] << std::endl;
	}
	printf("\n");
}

int getChar(std::string str, int radix) {
	return str[radix];
}
//	int t_num = 1;
//	for(int i = 0; i < radix; ++i) {
//		t_num = t_num << 1;
//	}
//	num = num & t_num;
//	if(num != 0) { 
//		for(int i = 0; i < radix; ++i) {
//			num = num >> 1;
//		}
//	}
//	return num;
//}

void countingSort(std::string* mas, size_t n, int radix) {
	size_t i;
	char count[RANGE] = {'\0'};
	for(i = 0; i < n; ++i) {
		++count[getChar(mas[i], radix) + 1];
	}
	for(i = 1; i < RANGE; ++i) {
		count[i] += count[i - 1];
	}
	std::string t_mas[n];
	for(i = 0; i < n; ++i) {
		t_mas[count[getChar(mas[i], radix)]++] = mas[i];
	}
	for(i = 0; i < n; ++i) {
		mas[i] = t_mas[i];
	}
	//printVector(mas, n);
}

void msdRadixPass(std::string* mas, size_t n, int radix) {
	if(n < 2) {
		return;
	}
	countingSort(mas, n, radix);
	bool flag = true;
	int start = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(getChar(mas[i], radix) != getChar(mas[i + 1], radix)) {
			msdRadixPass(mas, i + 1 - start, radix + 1);
			start = i + 1;
			flag = false;
		}
	}
	if(flag) {
		msdRadixPass(mas, n, radix + 1);
	} else {
		msdRadixPass(mas, n - start, radix + 1);
	}
}
//	printVector(mas, n);
//	bool flag = true;
//	int start = 0;
//	for(int i = 0; i < n - 1; ++i) {
//		if(digit(mas[i], radix) != digit(mas[i + 1], radix)) {
//			msdRadixPass(&mas[start], (i - start + 1), radix - 1);
//			start = i + 1;
//			//printVector(mas, n);
//			flag = false;
//		}
//	}
//	if(flag) {
//		msdRadixPass(mas, n, radix - 1);
//	} else {
//		msdRadixPass(&mas[start], (n - start), radix - 1);
//	}
//	
//}

void msdRadixSort(std::string* mas, size_t n) {
	msdRadixPass(mas, n, 0);
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
	
	std::vector<std::string> many_string;
//	many_string.push_back("jkgcjkytxd");
//	many_string.push_back("abfesh");
//	many_string.push_back("yrsx");
//	many_string.push_back("aesh");
//	many_string.push_back("rexxd");
	while(std::cin.good()) {
    std::string str;
    std::getline(std::cin, str);
    if (str.empty() || std::cin.eof()) break;
    many_string.push_back(str);
  }
//	printVector(&many_string[0], many_string.size());
	msdRadixSort(&many_string[0], many_string.size());
	printVector(&many_string[0], many_string.size());
	
//	int mas[] = {1, -1, -6514654, 7, 4, -9, 3, 5, 15, -5, 4, 5461, 48, 0, 15};
//	int n = 12;
//	msdRadixSort(mas, n);
//	printVector(mas, n);
  return 0;
}
