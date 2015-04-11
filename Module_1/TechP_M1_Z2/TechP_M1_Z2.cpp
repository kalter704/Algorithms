#include <iostream>

int main() {
    int *a, *b;
    unsigned int n, m, k;
    std::cin >> n;
    a = new int[n];					//считывание массива a
    for( int i = 0; i < n; ++i ) {
		std::cin >> a[i];
    }
    std::cin >> m;
    b = new int[m];					//считывание массива b
    for( int i = 0; i < m; ++i ) {
		std::cin >> b[i];
    }
    std::cin >> k;
    int i = 0, 
        j = m - 1,
        count = 0;
    while( ( i < n ) && ( j >= 0 ) ) {
		if( ( a[i] + b[j] ) == k ) {
			count++;
			i++;
            j--;
		} else {
			if( ( a[i] + b[j] ) > k ) {
				j--;
			} else {
            	i++;
			}
		} 
	}
    std::cout << count << std::endl;
    delete[] a;
    delete[] b;
	return 0;   
}


