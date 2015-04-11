#include <iostream>
//#include <fstream>

int main() {
    //std::ifstream fin("TechP_M1_Z2.txt");  
    int *a, *b;
    unsigned int n, m, k;
    //fin >> n;
    std::cin >> n;
    //std::cout << n << std::endl;
    a = new int[n];
    for( int i = 0; i < n; ++i ) {
    	//fin >> *(a + i);
		std::cin >> *(a + i);
        //std::cout << a[i] << ' ';
    }
    //fin >> m;
    std::cin >> m;
    //std::cout << std::endl << m << std::endl;
    b = new int[m];
    for( int i = 0; i < m; ++i ) {
		//fin >> *(b + i);
		std::cin >> *(b + i);
		//std::cout << b[i] << ' ';
    }
    //std::cout << std::endl;
    //fin >> k;
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
    //if( a == NULL ) std::cout << 1 << std::endl;
    //system("pause");
	return 0;   
}


