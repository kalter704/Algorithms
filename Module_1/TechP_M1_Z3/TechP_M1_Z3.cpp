#include <iostream>
#include <fstream>

int searchElement( int *a, int size ) {
	int first = 0,
		last = size;
	int result;
	while( first != last ) {
		int mid = (last + first) / 2;
		if( ( mid == 0 ) || ( mid == size ) ) {
			return a[mid];
		} else {
			if( ( a[mid - 1] < a[mid] ) && ( a[mid] < a[mid + 1] ) ) {
				first = mid;
			} else {
				if( ( a[mid - 1] > a[mid] ) && ( a[mid] > a[mid + 1] ) ) {
					last = mid;
				} else {
					if( ( a[mid - 1] < a[mid] ) && ( a[mid] > a[mid + 1] ) ) {
						return a[mid];
					}
				}
			}
		}
	}
	return a[first];
}

int main() {
	int *a, n;
	//std::ifstream fin("TechP_M1_Z3_04.txt");
	std::cin >> n;
	//fin >> n;
	//std::cout << n << std::endl;
	a = new int[n];
	for( int i = 0; i < n; ++i ) {
		//fin >> a[i];
		std::cin >> a[i];
		//std::cout << a[i] << std::endl;
	}
	
	int check = searchElement( a, n );
	std::cout << check << std::endl;
/*	if(check == -1) {
		std::cout << "ERROR" << std::endl;
	} else {
		std::cout << check << std::endl;	
	}
	*/
	delete[] a;
	return 0;
}
