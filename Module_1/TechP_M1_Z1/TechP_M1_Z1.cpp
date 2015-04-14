#include <iostream>

int NOD(int a, int b) {
  while(a != b) {
    if(a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return a;
}

int asd(int n) {
  int a;
  for(a = n / 2; NOD(a, (n - a)) != a; --a){}
  return a; 
}

int main() {
  int n, a;
  std::cin >> n;
  a = asd(n);
  std::cout << a << ' ' << ( n - a );
  return 0;
}
