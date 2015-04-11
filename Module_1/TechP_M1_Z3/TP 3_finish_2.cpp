#include <iostream>

int less_two_elem(int left, int right) {
  if(left < right) {
    return true;
  } else { 
    return false;
  }
}

int binary_search(int* a, int first, int last) {
  while(first != last) {
	int mid = (last + first) / 2;
    if(less_two_elem(a[mid - 1], a[mid])) {
      first = mid + 1;
    } else {
      last = mid;
    }
  }
  return first;
}

int gallop_search(int* a, int n) {
  int i = 0;
  for(i = 1; i < n; ++i) {
    if(!less_two_elem(a[i - 1], a[i])) {
      return i;
    }
  }
  return i;
}

int searchElement(int* a, int n) {
  int m = gallop_search(a, n);
  m = binary_search(a, m / 2, m - 1);
  return m;
}

int main() {
	int n;
	std::cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int check = searchElement(a, n);
	std::cout << check << std::endl;
	delete[] a;
	return 0;
}
