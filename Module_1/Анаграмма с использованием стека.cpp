#include <iostream>

struct Stack {
  int arr[20];
  int top = 0;
  char Top() {
    return arr[top - 1];
  }
  char pop() {
    return arr[--top];
  }
  void push(char ch) {
    arr[top++] = ch;
  }
};


int main() {
  char a[] = {'a', 'b', 'c'};
  char b[] = {'c', 'b', 'a'};
  int n = 3;
  int j = 0;
  Stack s;
  for(int i= 0; i < n; ++i) {
    s.push(a[i]);
    while(s.Top() == b[j]) {
      ++j;
      std::cout << s.pop();
    }
  }
  return 0;
}
