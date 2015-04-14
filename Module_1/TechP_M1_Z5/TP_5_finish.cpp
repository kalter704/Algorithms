#include <iostream>

const unsigned int SIZE_STACK = 7;
const int SIZE_STRING = 255;

struct DStack_L {
	private:
		char* mas;
		int top, sizeBuffer;
		bool isFull();
		bool isEmpty();
		void increaseStack();
	public:
		DStack_L(int n): top(-1), sizeBuffer(n) {
			mas = new char[sizeBuffer];
		}
		~DStack_L() {
			delete[] mas;
		}
		int top_stack() {
			if( isEmpty() == true) { return '\n'; }
			else { return mas[top]; }
		}
		int size() {
		  return sizeBuffer;
		}
		void push(char n);
		int pop();
};

bool DStack_L::isFull() {
	return (top == (sizeBuffer - 1));
}

bool DStack_L::isEmpty() {
	return (top == -1);
}

void DStack_L::increaseStack() {
	int lastSize = sizeBuffer;
	sizeBuffer *= 2;
	char* temp = new char[sizeBuffer];
	int count = 0;
	while(count <= top){
		temp[count] = mas[count];
		count++;
	}
	delete[] mas;
	mas = temp;
}

void DStack_L::push(char n) {
	if( isFull() == true ) { increaseStack(); }
	mas[++top] = n;
}

int DStack_L::pop() {
	if( isEmpty() == true) { return '\n'; }
	else { return mas[top--]; }
}

void growArray(char** str, int& size) {
  int t_size = size * 2;
  char* t_str = new char[t_size];
  for(int i = 0; i < size; ++i) {
    t_str[i] = (*str)[i];
  }
  delete[] (*str);
  (*str) = t_str;
  size = t_size;
}

bool fillingStackWithBrackets(char* str, DStack_L& stack) {
	int i = 0;
	while(str[i] != '\0') {
    char temp_char;
		if((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {
		  switch(str[i]) {
			  case ')':
				  temp_char = '(';			
				  break;
			  case '}':
				  temp_char = '{';
				  break;
			  case ']':
				  temp_char = '[';
				  break;
      }
      if(stack.top_stack() == temp_char) {
        stack.pop();
      } else {
        if((stack.top_stack() == '\n') || (stack.top_stack() == ')') ||
          (stack.top_stack() == '}') || (stack.top_stack() == ']')) {
          stack.push(str[i]);
        } else {
          return false;
        }
      }
	  } else {
	    stack.push(str[i]);
	  }
	  i++;
	}
	return true;
}

void outputBrackets(char* str, int& size, DStack_L& stack) {
  char* t_str = new char[size];
  int t_char = 0;
  while((stack.top_stack() == '(') || (stack.top_stack() == '{') || (stack.top_stack() == '[')) {
    char temp_char = stack.pop();
    switch(temp_char) {
      case '(':
        t_str[t_char++] = ')';
        break;
      case '{':
        t_str[t_char++] = '}';
        break;
      case '[':
        t_str[t_char++] = ']';
        break;
    }
  }
  t_str[t_char++] = '\0';
  while(stack.top_stack() != '\n') {
	  char temp_char = stack.pop();
	  switch(temp_char) {
	    case ')':
        std::cout << '(';
        break;
	    case '}':
		    std::cout << '{';
        break;
      case ']':
        std::cout << '[';
        break;
    }
  }
  std::cout << str << t_str;
  delete[] t_str;
}

bool restorationBrackets(char* str, int& size) {
  DStack_L stack(SIZE_STACK);
  if(!fillingStackWithBrackets(str, stack)) {
    return false;
  }
  outputBrackets(str, size, stack);
  return true;
}

void inputString(char** str, int& size) {
  char ch;
  int i = 0;
  while((ch = std::cin.get()) != '\n') {
    if(i == size) {
      growArray(str, size);
    }
    (*str)[i++] = ch; 
  }
  if(i == size) {
    growArray(str, size);
  }
  (*str)[i] = '\0'; 
}

int main() {
  int size = SIZE_STRING;
	char* str = new char[size];
	inputString(&str, size);
  if(!restorationBrackets(str, size)){
		std::cout << "IMPOSSIBLE";
		return 0;
	}
	delete[] str;
	return 0;
}
