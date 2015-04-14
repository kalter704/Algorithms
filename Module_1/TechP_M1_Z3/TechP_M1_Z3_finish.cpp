#include <iostream>			

int searchElement( int *a, int size ) {
	int first = 0,
		  last = size;
	int result;
	if( size == 2 ) {
		if( a[0] > a[1] ) {
			return 0;
		} else {
			return 1;
		}
	}
	while( first != last ) {
		int mid = (last + first) / 2;
		if( ( mid == first ) || ( mid == last ) ) {
			return mid;
		} else {
			if( ( a[mid - 1] < a[mid] ) && ( a[mid] < a[mid + 1] ) ) {
				first = mid;
			} else {
				if( ( a[mid - 1] > a[mid] ) && ( a[mid] > a[mid + 1] ) ) {
					last = mid;
				} else {
					if( ( a[mid - 1] < a[mid] ) && ( a[mid] > a[mid + 1] ) ) {
						return mid;
					}
				}
			}
		}
	}
	return first;
}

int main() {
	int *a, n;
	std::cin >> n;
	a = new int[n];
	for( int i = 0; i < n; ++i ) {
		std::cin >> a[i];
	}
	int check = searchElement( a, n );
	std::cout << check << std::endl;
	delete[] a;
	return 0;
}
