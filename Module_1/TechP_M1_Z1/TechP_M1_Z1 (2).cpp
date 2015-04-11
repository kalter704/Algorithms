#include <iostream>

int find_max_div(int n) {
  for(int i = 2; i * i <= n; ++i) {
    if((n % i) == 0) {
      return n / i;
    }
  }
  return n;
}

int main() {
  int n, a;
  std::cin >> n;
  a = find_max_div(n);
  if(a == n) {
    std::cout << '1' << ' ' << (n - 1);
  } else {
    std::cout << a << ' ' << (n - a);
  }
  return 0;
}
